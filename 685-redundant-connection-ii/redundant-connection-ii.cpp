class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);           // track parent of each node
        vector<int> cand1, cand2;               // two candidates when indegree == 2
        
        // Step 1: Find node with two parents (indegree 2)
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                // v already has a parent
                cand1 = {parent[v], v};   // first edge to v
                cand2 = e;                // second edge to v
            }
        }
        
        // Reset parent for DSU
        for (int i = 1; i <= n; ++i) parent[i] = i;
        
        // Helper DSU functions
        auto find = [&](auto& self, int x) -> int {
            if (parent[x] != x) 
                parent[x] = self(self, parent[x]);
            return parent[x];
        };
        
        auto unionSets = [&](int x, int y) -> bool {
            int px = find(find, x);
            int py = find(find, y);
            if (px == py) return false;  // cycle
            parent[px] = py;
            return true;
        };
        
        // Case 1: No node with indegree 2 → there is a cycle
        if (cand1.empty()) {
            for (auto& e : edges) {
                if (!unionSets(e[0], e[1])) {
                    return e;               // the edge that forms the cycle
                }
            }
        }
        
        // Case 2: There is a node with two parents
        // Try removing cand2 first (the later edge in input)
        for (auto& e : edges) {
            if (e == cand2) continue;       // skip the second edge
            if (!unionSets(e[0], e[1])) {
                // If removing cand2 still causes cycle, then cand1 is the answer
                return cand1;
            }
        }
        
        // If removing cand2 makes the graph valid, then cand2 is the answer
        return cand2;
    }
};