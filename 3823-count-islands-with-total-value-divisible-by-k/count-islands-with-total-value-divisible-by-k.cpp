class Solution {
public:
    vector<pair<int,int>> dr = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int vis[1001][1001];
    int n, m;

    long long dfs(int x, int y, vector<vector<int>>& g)
    {
        if(x >= n || y >= m)
            return 0;

        long long sum = g[x][y];
        vis[x][y] = true;
        for(int i = 0; i < 4; i++)
        {
            int dx = dr[i].first + x;
            int dy = dr[i].second + y;

            if(dx < n && dy < m && dx >= 0 && dy >= 0 && g[dx][dy] > 0 && !vis[dx][dy])
                sum += dfs(dx, dy, g);
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();       
        m = grid[0].size();       

        memset(vis, 0, sizeof(vis));
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] > 0)
                {
                    long long sum = dfs(i, j, grid);

                    if(sum % k == 0)
                        res++;
                }
            }
        }
        return res;
    }
};