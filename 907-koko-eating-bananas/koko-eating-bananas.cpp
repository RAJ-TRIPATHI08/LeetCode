class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(begin(piles), end(piles));
        int res = r;

        auto check = [&](int mid) {
            long long int time = 0;

            for(auto p : piles)
            {
                if(p <= mid)
                {
                    time += 1;
                }
                else
                {
                    if(p % mid == 0)
                        time += p/mid;
                    else
                        time += (p/mid) + 1;
                }
            }
            return time <= h;
        };

        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(check(mid))
            {
                r = mid - 1;
                res = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};