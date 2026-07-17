class Solution {
public:
    unordered_map<int, vector<int>> adj;
    
    bool dfs(int u, int d, vector<bool>& vis)
    {
        vis[u] = true;
        if(u == d)
            return true;

        for(auto v : adj[u])
        {
            if(!vis[v])
            {
                if(dfs(v, d, vis))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        return dfs(source, destination, vis);
    }
};