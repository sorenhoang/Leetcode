class Solution
{
public:
    static int n;
    static inline void add(string &s, int a)
    {
        for (int i = 1; i < n; i += 2)
        {
            const int d = (s[i] - '0' + a);
            s[i] = '0' + (d >= 10 ? d - 10 : d);
        }
    }

    static inline void rotate(string &s, int b)
    {
        //    return s.substr(n-b)+s.substr(0, n-b);
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
    }
    static string findLexSmallestString(string &s, int a, int b)
    {
        n = s.size();
        unordered_set<string> seen;
        string ans = string(n, '9');
        ;
        const int a0 = gcd(a, 10), b0 = gcd(n, b), A = 10 / a0, B = n / b0;
        const int sz = B * ((b0 & 1) ? A * A : A);
        seen.reserve(sz);

        queue<string> q;
        q.push(s);
        seen.insert(s);
        while (!q.empty())
        {
            string t = q.front();
            q.pop();
            ans = min(ans, t);
            string u = t;
            rotate(u, b);
            if (!seen.count(u))
            {
                q.push(u);
                seen.insert(u);
            }
            for (int i = a0; i < 10; i += a0)
            {
                add(t, i);
                if (!seen.count(t))
                {
                    q.push(t);
                    seen.insert(t);
                }
            }
        }
        return ans;
    }
};
int Solution::n;