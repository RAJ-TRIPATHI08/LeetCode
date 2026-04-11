class Solution {
public:
    typedef pair<int, int> P;
    int spanningTree(int V, vector<vector<P>>& adj) {
        // code here
        priority_queue<P, vector<P>, greater<P>> pq;       
        pq.push({0, 0});    
        vector<bool> inMST(V, false);
        
        int sum = 0;
        
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            if(inMST[node] == true)
                continue;
                
            inMST[node] = true;
            sum += wt;
            
            for(auto vec : adj[node])
            {
                int nbr_wt = vec.second;
                int nbr = vec.first;
                
                if(inMST[nbr] == false)
                    pq.push({nbr_wt, nbr});
            }
        }
        return sum;
    }

    vector<vector<P>> buildAdjList(vector<vector<int>>& points)
    {
        int n = points.size();
        vector<vector<P>> adj(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]); 
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        return adj;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<P>> adj = buildAdjList(points);
        int V = adj.size();

        return spanningTree(V, adj);
    }
};