class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;

        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            unordered_map<char, int> freq;
            for(int j = i; j < n; j++)
            {
                freq[s[j]]++;
                if(freq[s[j]] > 2)
                    break;

                res = max(res, j-i+1);
            }
        }

        return res;
    }
};