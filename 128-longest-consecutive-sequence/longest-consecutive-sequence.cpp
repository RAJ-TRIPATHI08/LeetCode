class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto n:nums) st.insert(n);

        int longestLength = 0;
        for(auto i:st)
        {
            if(st.find(i-1) == st.end())
            {
                int cnt = 1;
                int x = i;
                while(st.find(x+1) != st.end())
                {
                    x++;
                    cnt++;
                }
                longestLength = max(cnt, longestLength);
            }
        }
        return longestLength;
    }
};