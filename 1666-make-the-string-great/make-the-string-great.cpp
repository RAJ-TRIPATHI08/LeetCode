class Solution {
public:
    string makeGood(string s) {
        for(int i = 0; i < (int)s.size() - 1; i++)
        {
            if(i + 1 < s.size() && abs(s[i] - s[i+1]) == 32)
            {
                s.erase(i, 2);
                i = max(-1, i - 2);
            }
        }
        return s;
    }
};