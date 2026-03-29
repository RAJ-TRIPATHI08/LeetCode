class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2)
            return true;
        
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                for(int j = 0; j < s2.size(); j++)
                {
                    if(s2[j] == s1[i] && j - i == 2)
                        swap(s2[j], s2[i]);
                }
            }
        }

        return s1 == s2;
    }
};