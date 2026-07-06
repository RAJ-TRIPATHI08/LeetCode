class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> newInterval;

        int maxEnd = -1;

        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i][1] > maxEnd)
            {
                newInterval.push_back({intervals[i][0], intervals[i][1]});
                maxEnd = intervals[i][1];
            }
        }

        return newInterval.size();
    }
};