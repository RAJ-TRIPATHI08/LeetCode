class TreeAncestor {
public:
    int lg;
    int n;
    vector<vector<int>> u;
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        this->lg = 31 - __builtin_clz(n);        
        u.resize(n, vector<int>(lg+1, -1));

        for(int i = 0; i < n; i++)
            u[i][0] = parent[i];

        buildKthAncestorArray();
    }

    void buildKthAncestorArray() 
    {
        for(int j = 1; j < lg+1; j++)
        {
            for(int node = 0; node < n; node++)
            {
                if(u[node][j-1] != -1)
                {
                    u[node][j] = u[u[node][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i <= lg && node != -1; i++) 
        {
            if (k & (1 << i))
                node = u[node][i];
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */