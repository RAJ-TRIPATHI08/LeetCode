class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks),
            [](vector<int> v1, vector<int> v2){
                return (v1[1]-v1[0]) > (v2[1]-v2[0]); 
            });

        int energy = 0;
        int res = 0;

        for(vector<int> t : tasks)
        {
            int actual_i = t[0];
            int min_i = t[1];

            if(energy < min_i)
            {
                res += min_i - energy;
                energy = min_i;
            }

            energy -= actual_i;
        }

        return res;
    }
};