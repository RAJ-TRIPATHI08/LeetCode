class Solution {
public:
    string res;
    int cnt = 0;
    void solve(int n, string s, int k)
    {
        if(s.size() == n)
        {
            cnt++;
            if(cnt == k)
            {
                res = s;
                return;
            }
            s = "";
            return;
        }

        for(char ch : {'a','b','c'})
        {
            if(s.empty() || s.back() != ch)
                solve(n, s+ch, k);
        }
    }

    string getHappyString(int n, int k) {
        solve(n, "", k);
        return  res;
    }
};