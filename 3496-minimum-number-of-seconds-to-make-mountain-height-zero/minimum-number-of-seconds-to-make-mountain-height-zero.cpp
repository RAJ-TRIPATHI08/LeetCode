class Solution {
public:
    typedef long long ll;
    ll minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        auto check = [&](ll mid, vector<int>& workerTimes, int mH) {
            ll tH = 0;
            for(int t : workerTimes)
            {
                tH += (sqrt(2*mid/t + 0.25) - 0.5);

                if(tH >= mH)
                    return true;
            }   
            return tH >= mH;
        };

        ll tM = *max_element(workerTimes.begin(), workerTimes.end());

        ll l = 1;
        ll r = tM * ((ll)mountainHeight*(mountainHeight+1))/2;
        ll res = 0;

        while(l <= r)
        {
            ll mid = l + (r-l)/2;

            if(check(mid, workerTimes, mountainHeight))
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return res;
    }
};