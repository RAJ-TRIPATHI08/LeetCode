class Solution {
public:
    using ll = long long;
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));
        
        ll m = mass;
        for(int &n : asteroids)
        {
            if(n <= m)
                m += n;
            else
                return false;
        }
        return true;
    }
};