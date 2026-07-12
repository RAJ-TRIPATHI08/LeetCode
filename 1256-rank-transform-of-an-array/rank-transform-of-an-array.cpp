class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)
            return {};

        vector<int> temp = arr;
        vector<int> res(n);

        sort(begin(temp), end(temp));

        unordered_map<int, int> rank;
        int r = 1;
        for(int n : temp)
            if(rank.find(n) == rank.end())
                rank[n] = r++; 
        
        for(int i = 0; i < n; i++)
            res[i] = rank[arr[i]];

        return res;
    }
};