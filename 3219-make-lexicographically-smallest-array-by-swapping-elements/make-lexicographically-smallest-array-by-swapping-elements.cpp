class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> vec = nums;
        sort(begin(vec), end(vec));
        int n = nums.size();

        unordered_map<int, vector<int>> grp;
        unordered_map<int, int> grpId;
        unordered_map<int, int> pos;
        
        int id = 1;
        grp[id].push_back(vec[0]);
        grpId[vec[0]] = id;

        for(int i = 1; i < n; i++)
        {
            if(vec[i] - vec[i-1] > limit)
                id++;

            grp[id].push_back(vec[i]);
            grpId[vec[i]] = id;
        }

        for(int i = 0; i < n; i++)
        {
            int group = grpId[nums[i]];
            nums[i] = grp[group][pos[group]];
            pos[group]++;
        }
        return nums;
    }
};