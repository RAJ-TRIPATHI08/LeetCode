class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int n:nums)
            sum += n;
        
        cout << sum << endl;

        return (sum%2)? 0:nums.size()-1;
    }
};