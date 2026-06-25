class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;

        int cnt = 0;
        for(int i = 0; i < n; i++)
        {   
            int freq = 0;
            for(int j = i; j < n; j++)
            {
                if(nums[j] == target)
                    freq++;

                if(2*freq > j - i + 1)
                    cnt++;
            }
        }
        return cnt;
    }
}