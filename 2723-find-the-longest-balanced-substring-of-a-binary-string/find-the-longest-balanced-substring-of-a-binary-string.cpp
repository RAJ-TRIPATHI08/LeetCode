class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        if(s == "")
            return s.size();

        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; i)
        {
            int ones = 0;
            int zeroes = 0;

            while(i < s.size() && s[i] == '0')
            {
                zeroes++;
                i++;
            }

            while(i < s.size() && s[i] == '1')
            {
                ones++;
                i++;
            }

            res = max(res, 2*min(ones, zeroes));
        }

        return res;
    }
};