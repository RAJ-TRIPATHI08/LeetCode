class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> directions = {{1, 1},  {0, 1},   {1, 0},  {-1, 0},
                                      {0, -1}, {-1, -1}, {-1, 1}, {1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1)
            return -1;

        auto isSafe = [&](int x, int y) {
            return (x >= 0 && y >= 0 && x < n && y < n);
        };

        vector<vector<int>> res(n, vector<int>(n, INT_MAX));

        queue<P> pq;
        pq.push({0, {0, 0}});
        res[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.front();
            pq.pop();
            int d = curr.first;
            pair<int, int> p = curr.second;

            int x = p.first;
            int y = p.second;

            for (auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int dist = 1;

                if (isSafe(x_, y_) && grid[x_][y_] == 0 &&
                    d + dist < res[x_][y_]) {
                    pq.push({d + dist, {x_, y_}});
                    res[x_][y_] = d + dist;
                }
            }
        }
        return res[n - 1][n - 1] == INT_MAX ? -1 : res[n - 1][n - 1] + 1;
    }
};