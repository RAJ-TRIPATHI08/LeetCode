class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";

        for(auto s : words)
        {
            int w = 0;
            for(char ch : s)
            {
                int idx = ch - 'a';
                w += weights[idx];
            }

            w = w%26;
            char ch = 'a' + (25-w);
            res += ch;
        }

        return res;
    }
};