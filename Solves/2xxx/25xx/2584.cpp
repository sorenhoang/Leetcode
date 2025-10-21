class Solution
{
private:
    std::vector<int> factorizePrime(int x)
    {
        std::vector<int> output = {};
        while (!(x & 1))
        {
            output.push_back(2);
            x >>= 1;
        }
        int bound = std::sqrt(x) + 1;
        for (int d = 3; d < bound; d += 2)
        {
            while (x % d == 0)
            {
                output.push_back(d);
                x /= d;
            }
        }
        if (x > 1)
            output.push_back(x);
        return output;
    };
    void addFactors(std::vector<int> &primes, std::unordered_map<int, int> &chunk)
    {
        for (const int &prime : primes)
            ++chunk[prime];
    };
    void subtractFactors(std::vector<int> &primes, std::unordered_map<int, int> &chunk)
    {
        for (const int &prime : primes)
        {
            --chunk[prime];
            if (!chunk[prime])
                chunk.erase(prime);
        }
    };
    bool isCoPrime(std::unordered_map<int, int> &x, std::unordered_map<int, int> &y)
    {
        for (const auto &p : x)
        {
            if (y.count(p.first))
                return false;
        }
        return true;
    };

public:
    int findValidSplit(vector<int> &nums)
    {
        std::unordered_map<int, std::vector<int>> factorization;
        std::unordered_map<int, int> prefix, suffix;
        size_t n = nums.size();
        for (size_t i = 0; i < n; ++i)
        {
            if (!factorization.count(nums[i]))
                factorization[nums[i]] = factorizePrime(nums[i]);
            addFactors(factorization[nums[i]], suffix);
        }
        for (size_t i = 0; i < n - 1; ++i)
        {
            addFactors(factorization[nums[i]], prefix);
            subtractFactors(factorization[nums[i]], suffix);
            if (isCoPrime(prefix, suffix))
                return static_cast<int>(i);
        }
        return -1;
    }
};