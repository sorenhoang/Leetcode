class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int uselimit)
    {
        int n = values.size();

        // Pair each value with its corresponding label
        vector<pair<int, int>> list(n);
        for (int i = 0; i < n; i++)
        {
            list[i] = {values[i], labels[i]};
        }

        // Sort the list in descending order based on value
        sort(list.begin(), list.end(), greater<pair<int, int>>());

        unordered_map<int, int> mpl; // Tracks how many times each label has been used
        int total = 0;               // Total number of items selected
        int sum = 0;                 // Sum of selected item values

        for (int i = 0; i < n; i++)
        {
            auto [val, label] = list[i];

            // Skip if this label has reached its use limit
            if (mpl[label] == uselimit)
                continue;

            // Use this value and increment label count
            mpl[label]++;
            sum += val;
            total++;

            // Stop if we've selected enough items
            if (total == numWanted)
                break;
        }

        return sum;
    }
};