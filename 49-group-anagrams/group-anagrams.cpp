class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string s : strs)
        {
            int freq[26] = {};

            for(char ch : s)
                freq[ch - 'a']++;

            string key;

            for(int i = 0; i < 26; i++)
            {
                key += to_string(freq[i]);
                key += '#';
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;

        for(auto &it : mp)
            res.push_back(it.second);

        return res;
    }
};