class Solution {
    bool isPredecessor(string &a, string &b) {
        if (b.size() != a.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;  
            }
        }

        return i == a.size();
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
        [](string &x, string &y) {
            return x.size() < y.size();
        });

        vector<int> dp(n, 1);

        for(int i = n - 1; i >= 0; i--) 
        {
            for(int j = i + 1; j < n; j++) 
            {
                if(isPredecessor(words[i], words[j])) 
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};