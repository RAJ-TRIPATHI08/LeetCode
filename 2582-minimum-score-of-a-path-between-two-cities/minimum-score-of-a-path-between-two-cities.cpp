class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto e : roads) 
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> vis(n+1, false);
        queue<int> q;

        q.push(1);
        vis[1] = true;

        int res = INT_MAX;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto [nbr, wt] : adj[u])
            {
                res = min(res, wt);
                
                if(!vis[nbr])
                {
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }

        return res;
    } 
};