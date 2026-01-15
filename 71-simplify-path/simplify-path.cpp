class Solution {
public:
    void reverseStack(stack<string> &st) {
        stack<string> temp;

        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        st = temp;
    }

    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;

        while(i < path.length())
        {
            int start = i;
            int end = i + 1;

            while(end < path.length() && path[end] != '/')
            {
                end++;
            }
            string minPath = path.substr(start, end - start);
            i = end;

            if(minPath == "/" || minPath == "/.") continue;

            if(minPath != "/..")
            {
                st.push(minPath);
            }
            else if(!st.empty())
            {
                st.pop();
            }
        }

        if(st.empty()) return "/";
        else {
            string ans = "";
            reverseStack(st);
            while(!st.empty())
            {
                string ch = st.top();
                st.pop();
                ans += ch;
            }
            // reverse(ans.begin(), ans.end());
            return ans;
        }
    }
};