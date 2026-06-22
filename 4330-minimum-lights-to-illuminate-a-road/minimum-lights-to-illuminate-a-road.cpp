class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> b(n, 0);
        int reach = -1;
        for (int i = 0; i < n; i++) {
            if (lights[i] != 0)
                reach = max(reach, i + lights[i]);
            if (reach >= i) {
                b[i] = 1;
            }
        }
        reach = n + 1;
        for (int i = n - 1; i >= 0; i--) {
            if (lights[i] != 0)
                reach = min(reach, i - lights[i]);
            if (reach <= i) {
                b[i] = 1;
            }
        }
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) {
                if (cnt != 0)
                    res += ((cnt - 1) / 3) + 1;
                cnt = 0;
            } else
                cnt++;
        }
        if (cnt != 0)
            res += ((cnt - 1) / 3) + 1;
        return res;
    }
};