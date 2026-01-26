class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        string word = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
            {
                word += s[i];
            }
        }
        words.push_back(word);
        if(pattern.length() != words.size()) return false;
        
        unordered_map<char, string> mp;
        unordered_map<string, char> rev;
        
        for(int i = 0; i < words.size(); i++)
        {
            char ch = pattern[i];

            if(mp.count(ch) && mp[ch] != words[i]) return false;
            if(rev.count(words[i]) && rev[words[i]] != ch) return false;

            mp[ch] = words[i];
            rev[words[i]] = ch;
        }

        return true;
    }
};