class Solution {
public:
    typedef long long ll;
    ll subArrayRanges(vector<int>& nums) {

        auto sumSubarrayMins = [&] (vector<int>& arr) {
            int n = arr.size();

            auto pse = [&](vector<int>& arr) {
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

            auto nse = [&](vector<int>& arr) {
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

            ll res = 0; 
            for(int i = 0; i < n; i++)
            {
                ll r = NSE[i] - i;
                ll l = i - PSE[i];
                res += r * l * arr[i];
            }
            
            return res;
        };


        auto sumSubarrayMaxs = [&] (vector<int>& arr) {
            int n = arr.size();
            const int mod = 1e9 + 7;

            // Previous Greater Element
            auto pge = [&](const vector<int>& arr) {
                vector<int> res(n, -1);
                stack<int> st;

                for(int i = 0; i < n; i++) {
                    while(!st.empty() && arr[st.top()] < arr[i]) {
                        st.pop();
                    }
                    res[i] = st.empty() ? -1 : st.top();
                    st.push(i);
                }
                return res;
            };

            // Next Greater Element
            auto nge = [&](const vector<int>& arr) {
                vector<int> res(n, n);
                stack<int> st;

                for(int i = n - 1; i >= 0; i--) {
                    while(!st.empty() && arr[st.top()] <= arr[i]) {
                        st.pop();
                    }
                    res[i] = st.empty() ? n : st.top();
                    st.push(i);
                }
                return res;
            };

            vector<int> PGE = pge(arr);
            vector<int> NGE = nge(arr);

            ll res = 0;

            for(int i = 0; i < n; i++) {
                ll left  = i - PGE[i];
                ll right = NGE[i] - i;
                res = (res + (left * right) * arr[i]);
            }

            return res;
        };

        ll subArrMaxs = sumSubarrayMaxs(nums);
        ll subArrMins = sumSubarrayMins(nums);
        return subArrMaxs - subArrMins;
    }
};