class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        vector<pair<int, int>> S;
        for (auto s : squares)
        {
            S.push_back({s[1], s[2]});
        }
        sort(S.begin(), S.end());

        double total_area = 0;
        for (auto [_, l] : S)
        {
            total_area += (double)l * (double)l;
        }

        auto area_below_line = [&](const double &yline) -> double
        {
            double area = 0;
            for (auto [y, l] : S)
            {
                if (y > yline)
                    break;
                area += min((double)l, yline - y) * l;
            }
            return area;
        };

        double target = total_area / 2;
        double low = 0;
        double hig = 1e9;
        while ((hig - low) > 1e-5)
        {
            double mid = (low + hig) / 2;
            if (area_below_line(mid) < target)
            {
                low = mid;
            }
            else
            {
                hig = mid;
            }
        }
        return low;
    }
};