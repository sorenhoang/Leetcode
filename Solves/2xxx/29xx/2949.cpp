class Solution
{
public:
    long long beautifulSubstrings(string s, int k)
    {
        int jump;
        for (jump = 1; jump <= k; ++jump)
            if ((jump * jump) % k == 0)
                break;
        jump *= 2;

        string vowels = "aeiou";

        unordered_map<int, vector<int>> count;
        count[0].push_back(0);

        long long result = 0;
        int d = 0;
        for (int i = 1; i < s.length() + 1; ++i)
        {
            (vowels.find(s[i - 1]) != string::npos) ? d++ : d--;
            for (int j : count[d])
                result += ((i - j) % jump == 0);
            count[d].push_back(i);
        }

        return result;
    }
};