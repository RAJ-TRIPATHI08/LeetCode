class Solution {
public:
    int solve(string &s, int k, char a, char b) {
        int cur = 0;
        int used = 0;
        int ans = 0;

        for (char c : s) 
        {
            if (c == a || c == b) 
            {
                cur++;
            } 
            else if (used < k) 
            {
                cur++;
                used++;
            } 
            else 
            {
                cur--;
            }

            ans = max(ans, cur);
        }

        return ans;
    }

    int maxDistance(string s, int k) {
        return max({
            solve(s, k, 'N', 'E'),
            solve(s, k, 'N', 'W'),
            solve(s, k, 'S', 'E'),
            solve(s, k, 'S', 'W')
        });
    }
};