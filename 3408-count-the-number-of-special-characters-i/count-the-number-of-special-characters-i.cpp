class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, bool> mp;

        for(char c : word)
        {
            mp[c] = true;
        }

        int res = 0;
        for(auto p : mp)
        {
            char c = p.first;

            if(islower(c))
            {
                if(mp[toupper(c)])
                    res++;
            }
        }

        return res;
    }
};