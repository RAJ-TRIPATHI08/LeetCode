class Solution {
public:
    bool isCycleBFS(vector<vector<int>>& graph, int u, vector<bool>& vis, vector<bool>&inRec)
    {
        vis[u] = true;
        inRec[u] = true;

        for(int v:graph[u])
        {
            if(!vis[v] && isCycleBFS(graph, v, vis, inRec))
                return true;
            else if(inRec[v] == true)
                return true;
        }

        inRec[u] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        /* BFS approach using Kahn's algo
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
        sort(safeNodes.begin(), safeNodes.end()); */

        vector<bool> vis(V, false);
        vector<bool> inRec(V, false);

        for(int u = 0; u < V; u++)
        {
            if(!vis[u])
                isCycleBFS(graph, u, vis, inRec);
        }

        vector<int> safeNodes;
        for(int u = 0; u < V; u++)
            if(!inRec[u]) safeNodes.push_back(u);
            

        return safeNodes;
    }
};