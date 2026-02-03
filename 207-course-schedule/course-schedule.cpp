class Solution {
public:
    bool checkCycle(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree)
    {
        queue<int> q;
        int cnt = 0;
        for(int v = 0; v < indegree.size(); v++)
        {
            if(indegree[v] == 0)
            {
                q.push(v);
            }
        }

        while(!q.empty())
        {
            cnt++;
            for(auto v:adj[q.front()])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
            q.pop();
        }
        return cnt == n;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        int n = prerequisites.size();

        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < n; i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }    


        // if there is cycle so it is not possible to complete course
        // use toposort kahns algo to check it
        return checkCycle(adj, numCourses, indegree);
    }
};