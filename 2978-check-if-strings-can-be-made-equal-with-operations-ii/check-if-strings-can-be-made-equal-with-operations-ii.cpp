class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> freq(52, 0);

        for(int i = 0; i < s1.size(); i++)
        {
            int off = (i&1)*26;
            freq[s1[i] - 'a' + off]++;
            freq[s2[i] - 'a' + off]--;
        }

        for(int i = 0; i < 52; i++)
        {
            if(freq[i])
                return false;
        }

        return true;
    }
};