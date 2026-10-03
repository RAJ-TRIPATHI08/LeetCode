class Solution {
public:
    int longestValidParentheses(string s) {
        if(s == "") return 0;
        
        int n = s.length();
        stack<int> st;
        st.push(-1); // initially take -1 as boundary to obtain a valid ans
        int maxLen = 0;

        for(int i = 0; i < n; i++)
        {
            char ch = s[i];                     
            if(ch == '(')
            {
                // opening brace found so push its index
                st.push(i);
            } 
            else
            {
                // if ch == ')'
                st.pop();

                if(st.empty())
                {
                    // stack becomes empty so push a newBoundary for valid braces
                    // no '(' brace is present to match 
                    st.push(i);
                }
                else
                {
                    // a valid brace found obtain the maxLen of it
                    maxLen = max(maxLen, i - st.top());
                }
            }
        } 
        return maxLen;
    }
};