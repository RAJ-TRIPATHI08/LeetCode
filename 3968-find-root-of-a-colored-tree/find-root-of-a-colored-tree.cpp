class Solution {
public:
    bool check(int node, int par, vector<int> adj[], vector<int>& color) {

        if (par != -1) {

            if (color[node] == color[par] ||
                color[node] != (color[par] + 1) % 3) {
                return false;
            }
        }

        for (int child : adj[node]) {

            if (child != par) {

                if (color[child] == color[node] ||
                    color[child] != (color[node] + 1) % 3) {
                    return false;
                }

                if (!check(child, node, adj, color)) {
                    return false;
                }
            }
        }

        return true;
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int> adj[n];
        vector<int> color(n);

        for (int i = 0; i < n; i++) {
            if (colors[i] == 'R') {
                color[i] = 0;
            } else if (colors[i] == 'B') {
                color[i] = 1;
            } else {
                color[i] = 2;
            }
        }

        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int root = -1;

        vector<int> possibles;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            mp[colors[i]] = 1;

            for (int adjNode : adj[i]) {
                mp[colors[adjNode]]++;
            }

            if (adj[i].size() > 3) {
                return -1;
            }

            if (adj[i].size() == 3) {

                if (mp.size() < 3) {
                    return -1;
                }

            } else if (adj[i].size() == 2) {

                if (mp.size() == 2) {

                    if (root != -1) {
                        return -1;
                    }

                    root = i;
                } else {
                    if (mp.size() != 3)
                        return -1;
                }
            } else {

                if (mp.size() == 1) {
                    return -1;
                }

                possibles.push_back(i);
            }
        }

        if (root == -1) {

            for (int node : possibles) {
                if (check(node, -1, adj, color)) {
                    return node;
                }
            }

            return -1;
        }

        return check(root, -1, adj, color) ? root : -1;
    }
};