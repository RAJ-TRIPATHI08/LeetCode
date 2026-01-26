class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        int diff = 1e9;
        for(int i = 0; i < n - 1; i++)
            diff = min(diff, abs(arr[i] - arr[i+1]));

        vector<vector<int>> res;

        for(int i = 0; i < n - 1; i++)
            if(abs(arr[i] - arr[i+1]) == diff)  
                res.push_back({arr[i], arr[i+1]});
        return res;
    }
};