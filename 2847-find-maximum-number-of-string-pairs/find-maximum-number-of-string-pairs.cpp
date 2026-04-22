class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            string s = words[i];
            for(int j = i+1; j < n; j++)
            {
                string t = words[j];
                reverse(t.begin(), t.end());

                if(s == t)
                    res++;
            }
        }
        return res;
    }
};