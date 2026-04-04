class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patF;

        for(auto vec : matrix)
        {
            string pat = "";
            if(vec[0] == 0)
            {
                for(auto bit : vec)
                    pat += to_string(bit);
            }
            else
            {
                for(auto bit : vec)
                    pat += to_string(bit ^ 1);
            }
            patF[pat]++;
        }

        int maxRows = 0;

        for(auto p : patF)
        {
            maxRows = max(maxRows, p.second);
        }

        return maxRows;
    }
};