class Solution {
public:
    string lexPalindromicPermutation(string s, string t) {
        vector<int> F(26, 0);

        for(char ch : s)
            F[ch - 'a']++;

        int oddF = 0;
        char mid = '1';
        for(int i = 0; i < 26; i++)
        {
            if(F[i] & 1)
            {
                oddF++;
                mid = i + 'a';
            }
            F[i] /= 2;
        }
        
        if(oddF > 1)
            return "";

        int lLen = s.size()/2;
        string res;

        function<bool(string&, vector<int>&, string&, int, bool)> solve = [&] (string& curr, vector<int>& F, string& t, int idx, bool flag) -> bool{
            if(curr.size() == lLen)
            {
                string half = curr;
                string right = curr;
                reverse(begin(right), end(right));
                string candidate;
                if(mid != '1')
                {
                    candidate = half + mid + right;
                }
                else
                {
                    candidate = half + right;
                }

                if(candidate > t)
                {
                    res = candidate;
                    return true;
                }
                return false;
            }

            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                if(F[ch - 'a'] == 0)
                    continue;

                if(!flag && ch < t[idx])
                    continue;

                curr.push_back(ch);
                F[ch - 'a']--;

                bool isGreater = flag || ch > t[idx];

                if(solve(curr, F, t, idx + 1, isGreater))
                {
                    return true;
                }

                curr.pop_back();
                F[ch - 'a']++;
            }
            return false;
        };

        string curr;

        solve(curr, F, t, 0, false);
        return res;
    }
};