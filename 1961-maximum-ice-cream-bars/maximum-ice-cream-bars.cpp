class Solution {
public:
    int maxIceCream(vector<int>& costs, int c) {
        sort(costs.begin(), costs.end());

        int res = 0;
        for (int cost : costs) 
        {
            if (c < cost)
                break;
            c -= cost;
            res++;
        }

        return res;
    }
};