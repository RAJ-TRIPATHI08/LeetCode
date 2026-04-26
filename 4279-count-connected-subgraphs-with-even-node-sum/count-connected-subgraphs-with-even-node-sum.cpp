class Solution {
public:
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& vis, string& binary)
    {
        vis[u] = true;

        for(int v : adj[u])
        {
            if(!vis[v] && binary[v] == '1')
                dfs(adj, v, vis, binary);
        }
    }

    bool isConnectedWithEvenSum(vector<int>& nums, vector<vector<int>>& adj, string binary) 
    {
        int start = -1;
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(binary[i] == '1')
            {
                sum += nums[i];
                if(start == -1)
                    start = i;
            }
        }

        if(start == -1)
            return false;

        if(sum & 1)
            return false;
        
        vector<bool> vis(n, false);
        dfs(adj, start, vis, binary);

        for(int i = 0; i < n; i++)
        {
            if(binary[i] == '1' && !vis[i])
                return false;
        }
        return true;
    }

    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int res = 0;

        for(int mask = 1; mask < (1 << n); mask++)
        {
            string binary = bitset<32>(mask).to_string();
            binary = binary.substr(32-n);

            if(isConnectedWithEvenSum(nums, adj, binary))
                res++;
        }
        return res;
    }
};