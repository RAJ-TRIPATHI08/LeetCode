class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int r = grid[0][0] % x;

        // flatten the grid
        
        vector<int> nums;
        for(auto vec : grid)
        {
            for(int num : vec)
            {
                nums.push_back(num);
                if(num % x != r)
                    return -1;
            }
        }

        // make all element equal to the median
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = nums[n/2];

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res += abs(m - nums[i])/x;
        }

        return res;
    }
};