short st[201] = {-1}, top = 0;
class Solution
{
public:
    static int maximalRectangle(vector<vector<char>> &matrix)
    {
        const unsigned short row = matrix.size(), col = matrix[0].size();
        if (row == 1 && col == 1)
            return matrix[0][0] == '1';
        unsigned short h[201] = {0}; // height
        int maxArea = 0;

        for (int i = 0; i < row; i++)
        {
            top = 0; // stack will not be empty & st[0]=-1
            for (int j = 0; j <= col; j++)
            {
                // Count the successive '1's & store in h[j]
                h[j] = (j == col || matrix[i][j] == '0') ? 0 : h[j] + 1;

                // monotonic stack has at least element -1
                while (top > 0 && (j == col || h[j] < h[st[top]]))
                {
                    const int m = st[top--]; // pop
                    const int w = j - st[top] - 1;
                    const int area = h[m] * w;
                    maxArea = max(maxArea, area);
                }
                st[++top] = j; // push
            }
        }
        return maxArea;
    }
};
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();