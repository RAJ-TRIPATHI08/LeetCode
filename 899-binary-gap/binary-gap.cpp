class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int curr = 0;
        int res = 0;

        while(n > 0)
        {
            if((n&1) > 0)
            {
                res = (prev != -1)? max(res, curr - prev):res;
                prev = curr;
            }
            curr++;
            n >>= 1; 
        }

        return res;
    }
};