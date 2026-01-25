class Solution {
public:
    typedef long long ll;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        auto pse = [&](vector<int> arr) {
            int n = arr.size();

            vector<int> res(n, -1);
            stack<int> st;
            for(int i = 0; i < n; i++)
            {
                while(!st.empty() && arr[st.top()] > arr[i])
                {
                    st.pop();
                }
                
                res[i] = st.empty()? -1:st.top();
                st.push(i);
            }
            return res;
        };

        auto nse = [&](vector<int> arr) {
            int n = arr.size();
            
            vector<int> res(n, n);
            stack<int> st;
            for(int i = n-1; i >= 0; i--)
            {
                while(!st.empty() && arr[st.top()] >= arr[i])
                {
                    st.pop();
                }
                
                res[i] = st.empty()? n:st.top();
                st.push(i);
            }
            return res;
        };


        vector<int> NSE = nse(arr);
        vector<int> PSE = pse(arr);

        ll res = 0;  ll mod = 1e9 + 7;
        for(int i = 0; i < n; i++)
        {
            int r = NSE[i] - i;
            int l = i - PSE[i];
            res = (res + (1LL * r * l % mod) * arr[i]) % mod;
        }
        
        return res%mod;
    }
};