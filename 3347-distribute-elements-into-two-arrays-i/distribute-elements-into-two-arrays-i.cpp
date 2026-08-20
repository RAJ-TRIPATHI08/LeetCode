class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        queue<int> q1;
        queue<int> q2;

        q1.push(nums[0]);
        q2.push(nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            if(q1.back() > q2.back())
                q1.push(nums[i]);
            else
                q2.push(nums[i]);
        }

        vector<int> res;

        while(!q1.empty())
        {
            res.push_back(q1.front());
            q1.pop();
        }

        while(!q2.empty())
        {
            res.push_back(q2.front());
            q2.pop();
        }

        return res;
    }
};