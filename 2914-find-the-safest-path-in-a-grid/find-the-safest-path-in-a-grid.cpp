class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    typedef pair<int, pair<int,int>> P;

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1: Multi-source BFS
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(auto &dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_>=0 && y_>=0 && x_<n && y_<n && dist[x_][y_]==INT_MAX){
                    dist[x_][y_] = dist[x][y] + 1;
                    q.push({x_,y_});
                }
            }
        }

        // Step 2: Dijkstra (max heap)
        priority_queue<P> pq; // max heap
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], {0,0}});
        best[0][0] = dist[0][0];

        while(!pq.empty()){
            auto [safe, p] = pq.top(); pq.pop();
            int x = p.first, y = p.second;

            if(x == n-1 && y == n-1)
                return safe;

            for(auto &dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_>=0 && y_>=0 && x_<n && y_<n){
                    int newSafe = min(safe, dist[x_][y_]);

                    if(newSafe > best[x_][y_]){
                        best[x_][y_] = newSafe;
                        pq.push({newSafe, {x_, y_}});
                    }
                }
            }
        }

        return 0;
    }
};