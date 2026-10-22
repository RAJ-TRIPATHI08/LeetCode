class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        bool isSorted = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                isSorted = false;
                break;
            }
        }
        if (isSorted) return 0;

        int idx_zero = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx_zero = i;
                break;
            }
        }

        bool is_increasing_cycle = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx_zero + i) % n] != i) {
                is_increasing_cycle = false;
                break;
            }
        }

        if (is_increasing_cycle) {
            int cost_rotate = idx_zero;
            int cost_reverse_route = 1 + (n - idx_zero) + 1;
            return min(cost_rotate, cost_reverse_route);
        }

        bool is_decreasing_cycle = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx_zero - i + n) % n] != i) {
                is_decreasing_cycle = false;
                break;
            }
        }

        if (is_decreasing_cycle) {
            int new_idx_zero = (n - 1 - idx_zero) % n;
            int cost_rev_then_rot = 1 + new_idx_zero;
            int cost_rot_then_rev = ((idx_zero + 1) % n) + 1;
            return min(cost_rev_then_rot, cost_rot_then_rev);
        }

        return -1;
    }
};