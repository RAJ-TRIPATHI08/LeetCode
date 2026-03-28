class Solution {
public:
    vector<vector<int>> directions = {{1,1}, {0,1}, {1,0}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1)
            return -1;

        auto isSafe = [&](int x, int y){
            return (x >= 0 && y >= 0 && x < n && y < n);
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int lvl = 0;
        while(!q.empty())
        {
            int N = q.size();
            while(N--)
            {
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;

                if(x == n - 1 && y == n - 1)
                    return lvl + 1;

                for(auto dir : directions)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_, y_) && grid[x_][y_] == 0)
                    {
                        q.push({x_, y_});
                        grid[x_][y_] = 1;
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};