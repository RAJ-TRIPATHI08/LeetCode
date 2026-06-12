#include<bits/stdc++.h>

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> depth;
    int MOD = 1e9 + 7;
    int n;
    int cols;
    vector<vector<int>> up;

    void dfs(int node, int par)
    {
        up[node][0] = par;

        for(auto nbr : adj[node])
        {
            if(nbr == par)
                continue;

            depth[nbr] = depth[node] + 1;

            dfs(nbr, node);
        }
    }

    void buildKthAncestorArray() 
    {
        for(int j = 1; j < cols; j++)
        {
            for(int node = 0; node < n; node++)
            {
                if(up[node][j-1] != -1)
                {
                    up[node][j] = up[up[node][j-1]][j-1];
                }
            }
        }
    }

    int LCA(int u, int v)
    {
        if(depth[u] < depth[v])
            swap(u,v);

        int diff = depth[u] - depth[v];

        for (int i = 0; i < cols; i++) 
        {
            if(diff & (1 << i))
                u = up[u][i];
        }

        if(u == v)
            return u;

        for(int j = cols - 1; j >= 0; j--)
        {
            if(up[u][j] == -1)
                continue;

            if(up[u][j] != up[v][j])
            {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        cols = log2(n) + 1;

        for(auto e : edges)
        {
            int u = e[0] - 1;
            int v = e[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        depth.resize(n, 0);
        up.resize(n, vector<int>(cols, -1));

        dfs(0, -1);
        buildKthAncestorArray();

        vector<int> pow2(n + 1, 0);
        pow2[0] = 1;

        for(int i = 1; i <= n; i++)
            pow2[i] = (2LL * pow2[i - 1]) % MOD;

        vector<int> res;

        for(auto q : queries)
        {
            int u = q[0] - 1;
            int v = q[1] - 1;
        
            int lca = LCA(u, v);
            int d = depth[u] + depth[v] - 2 * depth[lca];

            if(d == 0)
                res.push_back(0);
            else
                res.push_back(pow2[d - 1]);
        }

        return res;
    }
};