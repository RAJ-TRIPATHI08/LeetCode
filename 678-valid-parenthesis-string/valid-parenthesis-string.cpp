class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> left, star;

        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            if(ch == '(')
            {
                left.push(i);
            }
            else if(ch == '*')
            {
                star.push(i);
            }
            else
            {
                if(left.empty() && star.empty()) return false;
                if(!left.empty()) left.pop();
                else star.pop();
            }
        }

        while(!left.empty() && !star.empty())
        {
            if(left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }

        return left.empty(); 
    }
};