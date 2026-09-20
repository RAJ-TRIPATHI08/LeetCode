class Solution {
public:
    int reverseDegree(string s) {
        int idx = 26;
        vector<int> deg(26, 0);

        for(int &n : deg)
        {
            n = idx;
            idx--;
        }

        int res = 0;
        int pos = 1;

        for(char c : s)
        {
            res += pos * deg[c - 'a'];
            pos++;
        }

        return res;
    }
};