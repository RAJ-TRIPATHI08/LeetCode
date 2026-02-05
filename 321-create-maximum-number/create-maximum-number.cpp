class Solution {
public:
     void merge(vector<int>& ans, vector<int>& a, vector<int>& b, int k)
    {
        int i = 0, j = 0;
        int m = a.size(), n = b.size();
        int p = 0;

        while(p < k)
        {
            if(i < m && j < n)
            {
                if(a[i] > b[j])
                {
                    ans[p++] = a[i++];
                }
                else if(a[i] < b[j])
                {
                    ans[p++] = b[j++];
                }
                else
                {
                    // a[i] == b[j], compare suffix manually
                    int x = i, y = j;
                    while(x < m && y < n && a[x] == b[y])
                    {
                        x++;
                        y++;
                    }

                    if(y == n)  // b ended => a is bigger
                        ans[p++] = a[i++];
                    else if(x == m) // a ended => b is bigger
                        ans[p++] = b[j++];
                    else if(a[x] > b[y])
                        ans[p++] = a[i++];
                    else
                        ans[p++] = b[j++];
                }
            }
            else if(i < m)
            {
                ans[p++] = a[i++];
            }
            else
            {
                ans[p++] = b[j++];
            }
        }
    }

    vector<int> solve(int k, vector<int>& nums) {
            int n = nums.size();
            if(k > n) return {};

            vector<int> ans;
            stack<int> st;
            int rem = n - k;
            st.push(nums[0]);

            for(int i = 1; i < n; i++)
            {
                while(!st.empty() && st.top() < nums[i] && rem > 0)
                {
                    st.pop();
                    rem--;
                }
                st.push(nums[i]);
            }

            while(rem--)
                st.pop();

            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> ans;
        for(int i = 0; i <= k; i++)
        {
            vector<int> temp1 = solve(i, nums1);
            vector<int> temp2 = solve(k-i, nums2);
            if(i > nums1.size() || k-i > nums2.size()) continue;

            vector<int> temp(k);
            merge(temp, temp1, temp2, k);
            if(temp.size() == k) ans = max(ans, temp); 
        }
        return ans;
    }
};