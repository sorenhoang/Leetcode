class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<pair<string, int>> listParens;
        listParens.emplace_back("", 0);
        n *= 2;

        for (int i = 1; i <= n; ++i) {
            vector<pair<string, int>> temp;

            for(auto paren : listParens)
            {
                temp.emplace_back(paren.first+ "(", paren.second+1);
                if(paren.second > 0)
                {
                    temp.emplace_back(paren.first+ ")", paren.second-1);
                }
            }

            listParens = temp;
        }

        vector<string> result;
        for(auto paren : listParens)
        {
            if(paren.second == 0)
            {
                result.push_back(paren.first);
            }
        }

        return result;
    }
};