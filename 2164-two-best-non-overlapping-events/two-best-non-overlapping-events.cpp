class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());

        int n = events.size();

        // suffix max value
        vector<int> suffixMax(n);

        suffixMax[n-1] = events[n-1][2];

        for(int i = n-2; i >= 0; i--)
        {
            suffixMax[i] = max(suffixMax[i+1], events[i][2]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int start = events[i][0];
            int end   = events[i][1];
            int value = events[i][2];

            int l = i + 1;
            int r = n - 1;
            int idx = n;

            while(l <= r)
            {
                int mid = l + (r - l)/2;

                if(events[mid][0] > end)
                {
                    idx = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            int total = value;

            if(idx != n)
                total += suffixMax[idx];

            ans = max(ans, total);
        }

        return ans;
    }
};