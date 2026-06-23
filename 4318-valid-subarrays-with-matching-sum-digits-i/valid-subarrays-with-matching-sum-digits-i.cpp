class Solution {
public:
    using ll = long long;
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<ll> pSum(n, 0);

        pSum[0] = nums[0];
        for(int i = 1; i < n; i++)
            pSum[i] = pSum[i-1] + nums[i];
        
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                ll sum = pSum[j] - (i > 0? pSum[i-1] : 0);
                ll t = abs(sum);

                int last = t % 10;

                while (t >= 10)
                    t /= 10;

                int first = t;

                if (first == x && last == x)
                    res++;
            }
        }

        return res;
    }
};