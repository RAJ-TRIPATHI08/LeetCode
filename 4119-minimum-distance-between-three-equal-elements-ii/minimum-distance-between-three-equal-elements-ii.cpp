class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        int res = INT_MAX;

        for(auto p : mp)
        {
            auto vec = p.second;
            if(vec.size() >= 3)
            {
                for(int I = 0; I <= vec.size() - 3; I++) 
                {
                    int i = vec[I];
                    int j = vec[I+1];
                    int k = vec[I+2];
                    int x = abs(i-j) + abs(j-k) + abs(k-i);
                    cout << x << endl;
                    res = min(res, x);       
                }    
            } 
        }
        return res == INT_MAX? -1 : res;
    }
};