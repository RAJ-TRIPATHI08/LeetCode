class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if(is_sorted(begin(s), end(s)))
            return 0;

        if(n == 2)
            return -1;

        char mn = 'z', mx = 'a';

        for(int i = 0; i < n; i++)
        {
            mn = min(mn, s[i]);
            mx = max(mx, s[i]);
        }

        if(s[0] == mn || s[n-1] == mx)
            return 1;

        for(int i = 1; i < n-1; i++)
        {
            if(s[i] == mn || s[i] == mx)
                return 2;
        }

        return 3;
    }
};