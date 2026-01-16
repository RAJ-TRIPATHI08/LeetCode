class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flips = k;
        int i = 0, j = 0;
        int n = nums.size();
        int maxOne = 0;

        while (j < n) {
            if (nums[j] == 0) {
                flips--;
            }

            while (flips < 0) {   // shrink window
                if (nums[i] == 0)
                    flips++;
                i++;
            }

            maxOne = max(maxOne, j - i + 1);
            j++;
        }

        return maxOne;
    }
};
