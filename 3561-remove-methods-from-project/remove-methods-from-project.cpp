class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& vis)
    {
        vis[u] = true;

        for(auto v : adj[u])
        {
            if(!vis[v])
                dfs(v, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
        }

        vector<bool> vis(n, false);
        dfs(k, adj, vis);

        vector<int> res;

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];

            if(!vis[u] && vis[v])
            {
                for(int i = 0; i < n; i++)
                    res.push_back(i);

                return res;
            }
        }

        for(int i = 0; i < n; i++)
            if(!vis[i])
                res.push_back(i);
        return res;
    }
};