class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> distinct(nums.begin(), nums.end());

        unordered_set<int> cur = {0};

        for (int round = 0; round < 3; round++) 
        {
            unordered_set<int> nxt;

            for (int x : cur) 
                for (int num : distinct) 
                    nxt.insert(x ^ num);

            cur = move(nxt);
        }

        return cur.size();
    }
};