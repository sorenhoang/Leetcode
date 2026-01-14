
const double eps = 1e-5;
const int N = 10 + 1e5;

int a[N], b[N], h[N], w[N];
int kth[N];
int n;

int buf[N];
int T;

/* ---------------------------------------------------------------------------------------------------- */
// Segment Tree
#define ls (i << 1)
#define rs (i << 1 | 1)
#define mid (L + R >> 1)

int lst, rst;
int st[4 * N], len[4 * N], cnt[4 * N];

void pushup(int i)
{
    st[i] = cnt[i] ? len[i] : st[ls] + st[rs];
}

void build(int i, int L, int R)
{
    st[i] = 0, len[i] = buf[R + 1] - buf[L], cnt[i] = 0;
    if (L == R)
        return;
    build(ls, L, mid);
    build(rs, mid + 1, R);
}

void update(int i, int L, int R, int l, int r, int val)
{
    if (r < L || R < l)
        return;
    if (l <= L && R <= r)
    {
        cnt[i] += val;
        st[i] = cnt[i] ? len[i] : (L == R ? 0 : st[ls] + st[rs]);
        return;
    }
    update(ls, L, mid, l, r, val);
    update(rs, mid + 1, R, l, r, val);
    pushup(i);
}

void build(int l, int r) { build(1, lst = l, rst = r); }
void update(int l, int r, int k) { update(1, lst, rst, l, r, k); }
int ask() { return st[1]; }

/* ---------------------------------------------------------------------------------------------------- */

class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {

        // Prework 0:   Obtain all the line segments.
        n = T = 0;
        for (auto &e : squares)
        {
            int x1 = e[0], y1 = e[1], x2 = e[0] + e[2], y2 = e[1] + e[2];
            ++n, a[n] = x1, b[n] = x2, h[n] = y1, w[n] = 1;
            ++n, a[n] = x1, b[n] = x2, h[n] = y2, w[n] = -1;
            buf[++T] = x1;
            buf[++T] = x2;
        }

        // Prework 1:   Sort the line segments (sorted by y-coordinate).
        for (int i = 1; i <= n; i++)
            kth[i] = i;
        sort(kth + 1, kth + n + 1, [&](auto &l, auto &r)
             { return h[l] < h[r]; });

        // Prework 2:   Construct a segment tree
        sort(buf + 1, buf + T + 1);
        T = unique(buf + 1, buf + T + 1) - buf - 1;
        build(1, T - 1);

        // Step 1:      Obtain the total area
        double tot = 0, len = 0, pre = 0;
        for (int i = 1; i <= n; i++)
        {
            int k = kth[i];
            tot += len * (h[k] - pre);

            int l = lower_bound(buf + 1, buf + T + 1, a[k]) - buf;
            int r = lower_bound(buf + 1, buf + T + 1, b[k]) - buf;
            update(l, r - 1, w[k]);
            len = ask();
            pre = h[k];
        }

        // Step 2:
        build(1, T - 1);
        len = pre = 0;

        double sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int k = kth[i];
            if (2 * (sum + len * (h[k] - pre)) >= tot)
                return (tot / 2 - sum) / len + pre;

            sum += len * (h[k] - pre);

            int l = lower_bound(buf + 1, buf + T + 1, a[k]) - buf;
            int r = lower_bound(buf + 1, buf + T + 1, b[k]) - buf;
            update(l, r - 1, w[k]);
            len = ask();
            pre = h[k];
        }

        return -1;
    }
};
