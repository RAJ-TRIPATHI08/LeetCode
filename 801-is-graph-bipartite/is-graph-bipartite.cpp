class Solution {
public:
    bool checkDFS(vector<vector<int>>& graph, int curr, vector<int>& color, int col)
    {
        if(color[curr] == -1)
            color[curr] = col;

        for(auto& v:graph[curr])
        {
            if(color[v] == color[curr])
                return false;          // adjacent nodes color is matched
            
            if(color[v] == -1)     // if not colored yet color it 
            {
                if(!checkDFS(graph, v, color, 1-col))
                    return false;
            }
        }
        return true;
    }

    bool checkBFS(vector<vector<int>>& graph, int curr, vector<int>& color, int col)
    {
        if(color[curr] == -1)
            color[curr] = col;

        queue<int> q;
        q.push(curr);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int v:graph[u])
            {
                if(color[v] == color[u])       // adjacent nodes have the same color
                    return false;
                else if(color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> color(V, -1);

        for(int u = 0; u < V; u++)
        {
            if(color[u] == -1)
            {
                if(checkBFS(graph, u, color, 1) == false)
                    return false;
            }
        }

        return true;
    }
};