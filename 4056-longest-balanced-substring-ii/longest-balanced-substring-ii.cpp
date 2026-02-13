class Solution {
public:
    int case2(string &s, char a, char b)
    {
        int n = s.size();
        int maxL = 0;
        
        int cnta = 0;
        int cntb = 0;
        unordered_map<int, int> diffMap;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != a && s[i] != b)
            {
                diffMap.clear();
                cnta = 0;
                cntb = 0;
                continue;
            }

            if(s[i] == a)  cnta++;
            if(s[i] == b)  cntb++;

            if(cnta == cntb) maxL = max(maxL, cnta+cntb);

            int diff = cnta - cntb;
            if(diffMap.count(diff))
                maxL = max(maxL, i - diffMap[diff]);
            else
                diffMap[diff] = i;
        }

        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int cnt = 1;
        int maxL = 0;

        // Case1
        for(int i = 1; i < n; i++)
        {
            if(s[i-1] == s[i])
                cnt++;
            else
            {
                maxL = max(maxL, cnt);
                cnt = 1;
            }
        }
        maxL = max(maxL, cnt);

        // Case2
        maxL = max(maxL, case2(s, 'a', 'b'));
        maxL = max(maxL, case2(s, 'b', 'c'));
        maxL = max(maxL, case2(s, 'c', 'a'));

        // Case3
        int cnta = 0;
        int cntb = 0;
        int cntc = 0;
        unordered_map<string, int> mp;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')  cnta++;
            if(s[i] == 'b')  cntb++;
            if(s[i] == 'c')  cntc++;

            if(cnta == cntb && cnta == cntc)
                maxL = max(maxL, cnta+cntb+cntc);
            
            int diffAB = cnta - cntb;
            int diffAC = cnta - cntc;

            string key = to_string(diffAB) + "_" + to_string(diffAC);

            if(mp.count(key))
            {
                maxL = max(maxL, i - mp[key]);
            }
            else
            {
                mp[key] = i;
            }
        } 
        return maxL;
    }
};