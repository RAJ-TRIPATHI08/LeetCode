class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int &n : nums)
        {
            string num = to_string(n);
            int val = 0;

            for(char ch : num)
                val += ch - '0';
            n = val;
        }

        return *min_element(begin(nums), end(nums));
    }
};