class Solution {
public:
    typedef long long ll;
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

    ll countPairs(int n, vector<vector<int>>& edges) {
        par.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) par[i] = i;

        // 1.Union all neigbhour edges for components
        for(auto vec:edges)
        {
            int u = vec[0];
            int v = vec[1];
            unionSet(u, v);
        }

        // 2.Store the size of components in a map
        unordered_map<int, int> mp;       // component, size

        for(int i = 0; i < n; i++)
        {
            int parent = find(i);     // repersentative of that component 
            // inc. the size of component
            mp[parent]++;
        }


        ll res = 0;
        ll rem = n;
        for(auto p:mp)
        {
            int size = p.second;
            // calc res by formula
            res += size * (rem - size);
            rem -= size;
        }
        return res;
    }
};