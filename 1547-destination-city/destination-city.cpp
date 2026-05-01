class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, vector<string>> adj;

        for(auto vec : paths)
        {
            string a = vec[0];
            string b = vec[1];

            adj[a].push_back(b);
            if(adj[b].empty())
                adj[b] = {};
        }

        for(auto p : adj)
        {
            auto s = p.first;
            auto vec = p.second;
            if(vec.empty())
                return s;
        }
        return "";
    }
};