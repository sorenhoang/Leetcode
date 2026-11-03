class Solution {
public:
    int minOperations(int n) {
        int cont = 0;
        int ans = 0;
        while(n)
        {
            if(n%2)
            {
                cont++;
            }
            else 
            {
                if(cont > 0)
                {
                    ans ++;
                    cont = (cont > 1);
                }
            }

            n /= 2;
        }

        ans += min(cont, 2);
        return ans;
    }
};
