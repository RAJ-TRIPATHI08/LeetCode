class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(vBars.begin(), vBars.end());
        sort(hBars.begin(), hBars.end());

        auto getConsecutiveBars = [&](vector<int> bars) {
            int n = bars.size();
            int consecutive = 1, res = 1;
            for(int i = 0; i < n - 1; i++)
            {
                if(bars[i] == bars[i+1] - 1)
                    consecutive++;
                else 
                    consecutive = 1;
                res = max(res, consecutive);
            }
            return res;
        };

        int vConsecutiveBars = getConsecutiveBars(vBars) + 1;
        int hConsecutiveBars = getConsecutiveBars(hBars) + 1;

        int minBars = min(vConsecutiveBars, hConsecutiveBars);

        return minBars * minBars;
    }
};