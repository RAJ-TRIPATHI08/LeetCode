class Solution {
public:
    bool checkCycle(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree, vector<int>& res)
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
            res.push_back(q.front());
            q.pop();
        }
        return cnt == n;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> res;
        bool ans = checkCycle(adj, numCourses, indegree, res);
        if(!ans)
            return {};
        
        reverse(res.begin(), res.end());
        return res;
    }
};