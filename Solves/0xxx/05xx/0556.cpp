class Solution {
public:
    long long nextGreaterElement(int num) {
        string str = std::to_string(num);

        for(int i = str.size() - 1 ; i >= 1; --i)
        {
            if(str[i] > str[i-1])
            {
                for(int id = str.size() - 1; id >= i; --id)
                {
                    if(str[id] > str[i-1])
                    {
                        swap(str[id], str[i-1]);
                        break;
                    }
                }   

                sort(str.begin() + i, str.end());
                long long ans = stoll(str);
                if(ans > INT_MAX) return -1;
                return ans;
            }
        }

        return -1;
    }
};
