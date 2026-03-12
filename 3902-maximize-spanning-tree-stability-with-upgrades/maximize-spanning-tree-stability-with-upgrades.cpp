class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);   // Path Compression
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        // Union by Rank
        if(rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if(rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    bool check(int n, vector<vector<int>>& edges, int k, int mid)
    {
        DSU dsu(n);

        vector<vector<int>> upgradeCandidates;

        for(auto e:edges)
        {
            int u = e[0];
            int v = e[1];

            int s = e[2];
            int m = e[3];

            if(m == 1)
            {
                if(s < mid)
                    return false;

                dsu.unionSet(u, v);
            }
            else
            {
                if(s >= mid)
                {
                    dsu.unionSet(u, v);
                }
                else if(2*s >= mid)
                {
                    upgradeCandidates.push_back({u, v});
                }
            }
        }
        for(auto edge : upgradeCandidates)
        {
            int u = edge[0];
            int v = edge[1];

            if(dsu.find(u) != dsu.find(v))
            {
                if(k <= 0)
                    return false;
                
                dsu.unionSet(u, v);
                k--;
            }
        }

        int root = dsu.find(0);

        for(int u = 1; u < n; u++)
        {
            if(dsu.find(u) != root)
                return false;
        }

        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);

        for(auto e:edges)
        {
            int u = e[0];
            int v = e[1];

            int s = e[2];
            int m = e[3];

            if(m == 1)
            {
                // must be included
                if(dsu.find(u) == dsu.find(v))
                    return -1;

                dsu.unionSet(u, v);
            }
        }

        int res = -1;

        int l = 1;
        int r = 2*1e5;

        while(l <= r)
        {
            int mid = l + (r-l)/2;

            if(check(n, edges, k, mid))
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return res;
    }
};