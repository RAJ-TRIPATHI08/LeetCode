class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();

        if(n < 10)
            return {};

        vector<string> res;
        unordered_map<string, int> freq;
        for(int i = 0; i < n - 9; i++)
            freq[s.substr(i, 10)]++;
        
        for(auto p : freq)
        {
            if(p.second > 1)
                res.push_back(p.first);
        }
        
        return res;
    }
};