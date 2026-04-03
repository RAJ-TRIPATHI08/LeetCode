class Solution {
public:
    string maximumXor(string s, string t) {
        int one = 0;
        for(char c : t)
            if(c == '1')
                one++;

        int zero = t.size()-one;

        string res = "";
        
        for(char c : s)
        {
            if(c == '0' && one > 0)
            {
                res += '1';
                one--;
            }
            else if(c == '1' && zero > 0)
            {
                res += '1';
                zero--;
            }
            else
            {
                res += '0';
            }
        }
        return res;
    }
};