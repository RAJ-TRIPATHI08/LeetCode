class Solution {
public:
    vector<string> ans;
    void solve(int n, string s)
    {
        if(s.size() == n)
        {
            ans.push_back(s);
            return;
        }

        for(char ch : {'a','b','c'})
        {
            if(s.empty() || s.back() != ch)
                solve(n, s+ch);
        }
    }

    string getHappyString(int n, int k) {
        solve(n, "");
        sort(ans.begin(), ans.end());
        if(k > ans.size())
            return "";
        
        return ans[k-1];
    }
};