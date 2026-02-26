class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> revAdj(V);
        vector<int> indegree(V, 0);

        for(int u = 0; u < V; u++)
        {
            for(int v:graph[u])
            {
                revAdj[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;

        for(int u = 0; u < V; u++)
        {
            if(indegree[u] == 0)
                q.push(u);
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            safeNodes.push_back(u);

            for(int v:revAdj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};