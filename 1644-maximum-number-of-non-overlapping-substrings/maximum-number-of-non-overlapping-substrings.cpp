class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        unordered_map<char, int> mp1, last;

        for(int i = 0; i < n; i++)
        {
            if(mp1.find(s[i]) == mp1.end())
                mp1[s[i]] = i;

            last[s[i]] = i;
        }

        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++)
        {
            if(mp1[s[i]] != i)
                continue;

            int r = last[s[i]];
            bool ok = true;

            for(int j = i; j <= r; j++)
            {
                if(mp1[s[j]] < i)
                {
                    ok = false;
                    break;
                }

                r = max(r, last[s[j]]);
            }

            if(ok)
                v.push_back({i, r});
        }

        vector<pair<int,int>> ans;

        for(auto x : v)
        {
            if(ans.empty())
            {
                ans.push_back(x);
            }
            else
            {
                auto last = ans.back();

                if(x.first > last.second)
                {
                    ans.push_back(x);
                }
                else if(x.second < last.second)
                {
                    ans.back() = x;
                }
            }
        }

        vector<string> res;

        for(auto x : ans)
            res.push_back(s.substr(x.first, x.second - x.first + 1));

        return res;
    }
};