class Solution {
    using ll = long long;

    ll MOD = 1e9 + 7;

    ll binPow(ll a, ll b) 
    {
        if (b == 0) return 1;

        ll half = binPow(a, b / 2);
        ll res = (half * half) % MOD;

        if (b & 1)
            res = (res * (a % MOD)) % MOD;

        return res;
    }

    int getMaxDepth(unordered_map<int, vector<int>>& adj, int node, int par)
    {
        int maxDepth = 0;

        for(auto nbr : adj[node])
        {   
            if(nbr == par) 
                continue;

            maxDepth = max(maxDepth, getMaxDepth(adj, nbr, node)+1);
        }

        return maxDepth;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
        
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d = getMaxDepth(adj, 1, -1);
        return binPow(2, d-1);
    }
};