class Solution {
public:
    int countOdds(int low, int high) {
        int res = 0;
        while(low <= high)
        {
            if(low == high)
            {
                if(high & 1)
                    res++;
                break;
            }
            if(low & 1)
                res++;
            if(high & 1)
                res++;
            low++;
            high--;
        }
        return res;
    }
};