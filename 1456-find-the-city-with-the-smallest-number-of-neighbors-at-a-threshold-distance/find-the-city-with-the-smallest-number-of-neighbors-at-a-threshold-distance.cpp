class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        int M = 1e9+7;
        
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(dist[i][k] != M && dist[k][j] != M)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9+7));

        for(int i = 0; i < n; i++)
            dist[i][i] = 0;

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        floydWarshall(dist);

        int res = -1;
        int minReachCnt = n;
        for(int i = 0; i < n; i++)
        {
            int reachCnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;

                if(dist[i][j] <= distanceThreshold)
                {
                    reachCnt++;
                }
            }

            if(reachCnt <= minReachCnt)
            {
                minReachCnt = reachCnt;
                res = i;
            }
        }

        return res; 
    }
};