class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost), end(cost), greater<int>());

        int c = 0;
        for(int i = 0; i < cost.size(); i++)
        {
            if(i % 3 != 2)
                c += cost[i];
        }
        return c;
    }
};