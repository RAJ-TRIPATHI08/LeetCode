class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for(int i = 0; i < n; i++)
        {
            unordered_set<int> even, odd;
            for(int j = i; j < n; j++)
            {
                int num = nums[j];
                if(num & 1)
                    odd.insert(num);
                else
                    even.insert(num);

                if(odd.size() == even.size())
                    res = max(res, j - i + 1);
            }
        }

        return res;
    }
};