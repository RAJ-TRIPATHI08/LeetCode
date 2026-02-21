class Solution {
public:
    vector<int> par;
    vector<int> rank;
    
    int find(int x)
    {
        
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    
    void unionSet(int u, int v)
    {
        int parU = find(u);
        int parV = find(v);
        
        if(parU == parV) return;
        
        if(rank[parU] > rank[parV])
        {
            par[parV] = parU;
        }
        else if(rank[parU] < rank[parV])
        {
            par[parU] = parV;
        }
        else
        {
            par[parV] = parU;
            rank[parU]++;
        }
    }

    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& vis)
    {
        vis[u] = true;

        for(int v:adj[u])
        {
            if(!vis[v])
            {
                dfs(adj, v, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        // unordered_map<int, vector<int>> adj(n);
        // vector<bool> vis(n, false);
        
        // for(auto p:connections)
        // {
        //     adj[p[0]].push_back(p[1]);
        //     adj[p[1]].push_back(p[0]);
        // }

        // int cnt = 0;
        // for(int u = 0; u < n; u++)
        // {
        //     if(!vis[u])
        //     {
        //         cnt++;
        //         dfs(adj, u, vis);
        //     }
        // }

        // return cnt - 1;

        par.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
            par[i] = i;

        for(auto vec: connections)
        {
            int a = find(vec[0]);
            int b = find(vec[1]);

            if(a != b) 
            {
                unionSet(a, b);
                n--;
            }
        }

        return n - 1;
    }
};