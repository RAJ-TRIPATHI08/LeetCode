class Solution {
public:
    vector<int> par, rank;

    int find(int u)
    {
        if(par[u] == u)
            return u;

        return par[u] = find(par[u]);
    }

    void Union(int u, int v)
    {
        int pU = find(u);
        int pV = find(v);

        if(pU > pV)
        {
            par[pV] = pU;
        }
        else if(pV > pU)
        {
            par[pU] = pV;
        }
        else
        {
            par[pU] = pV;
            rank[pV]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n+1, 0);
        par.resize(n+1);

        for(int i = 0; i < n+1; i++)
            par[i] = i;

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];

            if(find(u) == find(v))
                return {u, v};

            Union(u, v);
        }

        return {};
    }
};