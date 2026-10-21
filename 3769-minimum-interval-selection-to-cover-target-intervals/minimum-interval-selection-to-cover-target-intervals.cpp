class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals,
                     vector<vector<int>>& targetIntervals) {

        sort(targetIntervals.begin(), targetIntervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if(a[0] != b[0])
                     return a[0] < b[0];
                 else
                     return a[1] > b[1];
             });

        vector<vector<int>> target;

        for(int i = 0; i < targetIntervals.size(); i++)
        {
            if(target.empty() ||
               targetIntervals[i][0] > target.back()[1])
            {
                target.push_back(targetIntervals[i]);
            }
            else
            {
                target.back()[1] = max(target.back()[1],
                                       targetIntervals[i][1]);
            }
        }

        sort(availableIntervals.begin(), availableIntervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] < b[0];
             });

        int i = 0;
        int j = 0;
        int curr = target[0][0];
        int res = 0;

        while(j < target.size())
        {
            int maxReach = -1;

            while(i < availableIntervals.size() &&
                  availableIntervals[i][0] <= curr)
            {
                maxReach = max(maxReach, availableIntervals[i][1]);
                i++;
            }

            if(maxReach == -1)
                return -1;

            while(j < target.size() && target[j][1] <= maxReach)
            {
                j++;
            }

            res++;

            if(j == target.size())
                return res;

            curr = max(maxReach, target[j][0]);
        }

        return res;
    }
};