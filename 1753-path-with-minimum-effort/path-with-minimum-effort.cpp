class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        auto isSafe = [&](int x, int y) {
            return (x >= 0 && y >= 0 && x < m && y < n);
        };

        vector<vector<int>> res(m, vector<int>(n, INT_MAX));


        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0,0}});
        res[0][0] = 0;

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int diff = curr.first;
            pair<int, int> p = curr.second;
            
            int x = p.first;
            int y = p.second;

            for(auto dir : directions)
            {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_))
                {
                    int d = max(diff, abs(heights[x][y] - heights[x_][y_]));
                    if(d < res[x_][y_])
                    {
                        pq.push({d, {x_, y_}});
                        res[x_][y_] = d;
                    }
                }
            }
        }

        return res[m-1][n-1];
    }
};