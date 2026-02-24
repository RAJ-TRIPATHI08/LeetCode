class Solution {
  public:
     vector<int> dx = {-1, 0, 0, 1};
     vector<int> dy = {0, -1, 1, 0};
    
    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& vis, int n, int m)
    {
        vis[x][y] = true;
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1' && !vis[nx][ny])
                dfs(grid, nx, ny, vis, n, m);
        }
    }
  
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
    
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(grid, i, j, vis, n, m);
                    res++;
                }
            }
        }
        return res;
    }
};