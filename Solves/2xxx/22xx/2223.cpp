class Solution
{
private:
    using ll = long long int;
    struct StringHash
    {
        string s;
        int n;
        ll p1 = 313, m1 = 1e9 + 7;
        ll p2 = 379, m2 = 1e9 + 9;
        vector<ll> p_pow1, p_pow2, h1, h2, inv_pow1, inv_pow2;
        ll mod = 1e9 + 7;
        ll power(ll a, ll b, ll mod)
        {
            ll ans = 1;
            a %= mod;
            while (b > 0)
            {
                if (b & 1)
                {
                    ans = (ans * a) % mod;
                }
                a = (a * a) % mod;
                b >>= 1;
            }
            return ans;
        }
        ll modInv(ll a, ll mod) { return power(a, mod - 2, mod); }

        StringHash(const string &str) : s(str)
        {
            n = s.length();
            p_pow1.resize(n);
            p_pow2.resize(n);
            h1.resize(n + 1, 0);
            h2.resize(n + 1, 0);
            inv_pow1.resize(n);
            inv_pow2.resize(n);
            p_pow1[0] = 1;
            p_pow2[0] = 1;
            inv_pow1[0] = 1;
            inv_pow2[0] = 1;
            ll inv_p1 = modInv(p1, m1);
            ll inv_p2 = modInv(p2, m2);
            for (int i = 1; i < n; i++)
            {
                p_pow1[i] = (p_pow1[i - 1] * p1) % m1;
                p_pow2[i] = (p_pow2[i - 1] * p2) % m2;
                inv_pow1[i] = (inv_pow1[i - 1] * inv_p1) % m1;
                inv_pow2[i] = (inv_pow2[i - 1] * inv_p2) % m2;
            }
            for (int i = 0; i < n; i++)
            {
                h1[i + 1] = (h1[i] + (s[i] - 'a' + 1) * p_pow1[i]) % m1;
                h2[i + 1] = (h2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;
            }
        }
        pair<ll, ll> get_hash(int l, int r)
        {
            ll res1 = (h1[r + 1] - h1[l] + m1) % m1;
            ll res2 = (h2[r + 1] - h2[l] + m2) % m2;
            res1 = (res1 * inv_pow1[l]) % m1;
            res2 = (res2 * inv_pow2[l]) % m2;
            return make_pair(res1, res2);
        }
        pair<ll, ll> concat(pair<ll, ll> left, pair<ll, ll> right, int len_right)
        {
            ll new1 = (left.first + right.first * p_pow1[len_right]) % m1;
            ll new2 = (left.second + right.second * p_pow2[len_right]) % m2;
            return {new1, new2};
        }
    };

public:
    long long sumScores(string s)
    {
        StringHash hs(s);
        ll n = s.size(), ans = 0;
        for (ll i = n - 1; i >= 0; i--)
        {
            ll s = 0, e = n - i - 1, mid, res = 0;
            while (s <= e)
            {
                mid = s + (e - s) / 2;
                if (hs.get_hash(0, mid) == hs.get_hash(i, mid + i))
                {
                    res = mid + 1;
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            ans += res;
        }
        return ans;
    }
};