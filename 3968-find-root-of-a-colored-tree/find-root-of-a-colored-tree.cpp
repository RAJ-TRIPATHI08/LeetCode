class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string col) {
        int n = edges.size() + 1;
        map<char, char> mp;
        mp['R'] = 'B';
        mp['B'] = 'W';
        mp['W'] = 'R';

        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            if(col[u] == col[v])
                return -1;

            if(mp[col[u]] == col[v])
            {
                if(inDegree[v] == 1)
                    return -1;
                inDegree[v] = 1;
                adj[u].push_back(v);
                if(adj[u].size() > 2)
                    return -1;
            } 
            else
            {
                if(inDegree[u] == 1)
                    return -1;
                inDegree[u] = 1;
                adj[v].push_back(u);
                if(adj[v].size() > 2)
                    return -1; 
            }
        }
        
        int res;
        for(int u = 0; u < n; u++)
        {
            if(inDegree[u] == 0)
                return u;
        }
        return -1;
    }
};