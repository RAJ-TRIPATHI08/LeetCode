class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        cout << m << " " << n;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int x = 0, y = 0;
        vis[x][y] = true;
        for(int i = 0; i < m*n; i++)
        {
            int dx = x;
            int dy = y;
            if(grid[x][y] == 'R')
            {
                dy++;
            }
            else if(grid[x][y] == 'D')
            {
                dx++;
            }
            else if(grid[x][y] == 'L')
            {
                dy--;
            }else if(grid[x][y] == 'U')
            {
                dx--;
            }

            if(dx >= 0 && dx < m && dy >= 0 && dy < n && !vis[dx][dy])
            {
                x = dx;
                y = dy;
                vis[x][y] = true;
            }
            else
            {
                return {x, y};
            }
        }

        return {x, y};
    }
};