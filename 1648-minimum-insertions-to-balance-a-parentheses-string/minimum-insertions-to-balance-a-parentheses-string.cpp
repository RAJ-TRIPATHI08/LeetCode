class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int res = 0;
        
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            char c = s[i];
            if(c == '(')
            {
                st.push(i);
            }
            else
            {
                if(i + 1 < n && s[i+1] == ')')
                {
                    if(!st.empty())
                        st.pop();
                    else
                        res += 1;
                    i++;
                }
                else
                {
                    res++;
                    if(!st.empty())
                        st.pop();
                    else
                        res++;
                }
            }
        }

        return res + 2*st.size();
    }
};