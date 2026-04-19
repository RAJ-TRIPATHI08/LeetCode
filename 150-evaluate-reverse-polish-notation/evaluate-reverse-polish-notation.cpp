class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> st;

        for(auto token : tokens)
        {
            if(token == "+" || token == "*" || token == "-" || token == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                if(token == "+")
                    st.push(b+a);
                else if(token == "-")
                    st.push(b-a);
                else if(token == "*")
                    st.push(b*a);
                else 
                    st.push(b/a);
            }
            else
                st.push(stoi(token));
        }

        res = st.top();
        st.pop();
        return res;
    }
};