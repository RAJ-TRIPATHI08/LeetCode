class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;  // rem->cnt

        for(int n : arr)
        {
            int rem = ((n%k)+k)%k;
            mp[rem]++;
        }

        for(auto [r, cnt] : mp)
        {
            if(r == 0)
            {
                if(cnt%2 != 0)
                    return false;
            }
            else
            {
                if(mp[r] != mp[k-r])
                    return false;
            }
        }

        return true;
    }
};