class Solution {
public:
    long long countCommas(long long n) {
        if (n <= 999)
            return 0;

        long long totalCommas = 0;
        long long rangeStart = 1000;
        long long rangeEnd = rangeStart * 1000 - 1;
        int commas = 1;

        while (rangeStart <= n) {
            long long numbers = (min(n, rangeEnd) - rangeStart + 1);
            totalCommas += 1LL * commas * numbers;

            if (rangeEnd > n)
                break;

            rangeStart = rangeStart * 1000;
            rangeEnd = rangeStart * 1000 - 1;
            commas++;
        }
        return totalCommas;
    }
};