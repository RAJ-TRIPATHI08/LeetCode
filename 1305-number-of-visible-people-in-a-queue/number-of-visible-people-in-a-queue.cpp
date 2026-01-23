class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> answer(n, 0);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--)
        {
            int cnt = 0;
            while(!st.empty() && st.top() < heights[i])
            {
                st.pop();     // pop untill a tall or same height person found
                cnt++;            
            }

            if(!st.empty()) cnt++;      // if a taller or same height person is there

            answer[i] = cnt;

            st.push(heights[i]);
        }
        return answer;
    }
};