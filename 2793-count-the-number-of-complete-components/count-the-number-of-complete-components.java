class Solution {
    HashMap<Integer, List<Integer>> adjList;
    boolean []vis;

    public int countCompleteComponents(int n, int[][] edges) {
        adjList = new HashMap<>();
        vis = new boolean[n];

        for(int []e : edges)
        {
            int u = e[0];
            int v = e[1];

            if(!adjList.containsKey(u))
                adjList.put(u, new ArrayList<>());
            if(!adjList.containsKey(v))
                adjList.put(v, new ArrayList<>());

            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }

        int res = 0;
         
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                int []temp = dfs(i);

                int ncnt = temp[0], e = temp[1];

                if(ncnt*(ncnt-1) == e || ncnt == 1)
                    res++;
            }
        }
        return res;
    }

    int[] dfs(int node)
    {
        int ret[] = new int[2];

        vis[node] = true;
        ret[0] += 1;

        List<Integer> list = adjList.get(node);

        if(list == null)
            return ret;

        ret[1] += list.size();

        for(int i = 0; i < list.size(); i++)
        {
            if(vis[list.get(i)])
                continue;

            int t[] = dfs(list.get(i));
            ret[0] += t[0];
            ret[1] += t[1];
        }
        return ret;
    }
}