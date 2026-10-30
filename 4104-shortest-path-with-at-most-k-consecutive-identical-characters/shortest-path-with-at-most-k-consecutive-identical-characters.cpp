class Solution {
public:
    using ll = long long;

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        vector<vector<ll>> dist(n, vector<ll>(k + 1, LLONG_MAX));

        priority_queue<
            tuple<ll, int, int>,
            vector<tuple<ll, int, int>>,
            greater<tuple<ll, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty())
        {
            auto [d, node, cnt] = pq.top();
            pq.pop();

            if(d > dist[node][cnt])
                continue;

            if(node == n-1)
                return d;

            for(auto [v, wt] : adj[node])
            {
                int newCnt = 1;

                if(labels[node] == labels[v])
                    newCnt = cnt + 1;

                if(newCnt <= k && d + wt < dist[v][newCnt])
                {
                    dist[v][newCnt] = d + wt;
                    pq.push({dist[v][newCnt], v, newCnt});
                }
            }
        }

        return -1;
    }
};