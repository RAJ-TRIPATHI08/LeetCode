class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
        visited[x][y] = true;

        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if(grid[nx][ny] != grid[x][y])
                continue;

            if(nx == px && ny == py)
                continue;

            if(visited[nx][ny])
                return true;

            if(dfs(nx, ny, x, y, grid))
                return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j]) {
                    if(dfs(i, j, -1, -1, grid))
                        return true;
                }
            }
        }
        return false;
    }
};
