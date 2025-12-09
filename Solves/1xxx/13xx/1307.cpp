class Solution
{
    using Symbol2Code = std::array<std::int32_t, 26>;
    using Symbol2Flag = std::array<bool, 26>;
    using Digit2Flag = std::array<bool, 10>;

    // Operation sign e.g. word1 + word2 - result = 0;
    enum Sign
    {
        plus = 1,
        minus = -1,
    };

    struct SymbolCode
    {
        std::int8_t symbol;
        std::int32_t code;

        friend bool operator>(const SymbolCode &lhs, const SymbolCode &rhs) noexcept
        {
            // result code is negative value
            return std::abs(lhs.code) > std::abs(rhs.code);
        }
    };

public:
    bool isSolvable(vector<string> &words, string result)
    {
        Symbol2Code symbol2code;
        Symbol2Flag symbol_can_be_0; // Not all characters can be encoded as 0 because leading
                                     // characters can't unless it's a digit.
        symbol2code.fill(0);
        symbol_can_be_0.fill(true);

        for (const auto &word : words)
        {
            encode<plus>(word, symbol2code, symbol_can_be_0);
        }
        encode<minus>(result, symbol2code, symbol_can_be_0);

        std::vector<SymbolCode> codes;
        codes.reserve(26);

        for (std::int8_t i = 0; i < 26; ++i)
        {
            if (!symbol2code[i])
            {
                continue;
            }
            codes.push_back({
                .symbol = i,
                .code = symbol2code[i],
            });
        }
        std::sort(codes.begin(), codes.end(), std::greater<SymbolCode>{});

        Digit2Flag digit2flag;
        digit2flag.fill(false);
        return track(/*sum*/ 0, digit2flag, codes, symbol_can_be_0);
    }

private:
    template <Sign sign>
    void encode(const std::string &word, Symbol2Code &symbol2code,
                Symbol2Flag &symbol_can_be_0)
    {
        std::int32_t code{sign};
        // Let's encode the symbol into number -
        // the symbol index corresponds to the digit in the code number.
        // e.g. ["ABC", "CBA"] -> {A -> 101, B -> 20, C -> 101}
        for (std::int32_t i = word.size() - 1; ~i; --i)
        {
            const auto c = word[i];
            symbol2code[c - 'A'] += code;
            code *= 10;
        }
        // Number that can start with zero can only be single digit numbers.
        if (word.size() > 1)
        {
            const auto c = word[0];
            symbol_can_be_0[c - 'A'] = false;
        }
    }

    // Stop recursion
    template <std::int32_t index>
        requires(index == 26)
    bool track(auto &&...)
    {
        return false;
    }

    template <std::int32_t index = 0>
        requires(index < 26)
    bool track(std::int32_t sum,
               Digit2Flag &digit2flag,
               const std::vector<SymbolCode> &codes,
               const Symbol2Flag &symbol_can_be_0)
    {
        if (index == codes.size())
        {
            return sum == 0;
        }
        const auto &elem = codes[index];

        if (std::abs(sum) > 9 * std::abs(elem.code) * (codes.size() - index))
        {
            return false;
        }

        for (std::int32_t digit = 0; digit < 10; ++digit)
        {
            if (digit2flag[digit])
            {
                continue;
            }

            if (digit == 0 && !symbol_can_be_0[elem.symbol])
            {
                continue;
            }
            digit2flag[digit] = true;
            if (track<index + 1>(sum + digit * elem.code, digit2flag, codes, symbol_can_be_0))
            {
                return true;
            }
            digit2flag[digit] = false;
        }

        return false;
    }
};