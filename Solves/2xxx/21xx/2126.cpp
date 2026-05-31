class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int max_mass = asteroids.back();
        long long cur = mass;
        for(int a_mass : asteroids)
        {
            if(cur < a_mass)
            {
                return false;
            }
            
            cur += a_mass;
            if(cur >= max_mass)
            {
                return true;
            }
        }
        return true;
    }
};