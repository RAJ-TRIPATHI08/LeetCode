class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if((j-i+1) % 2)
                {
                    for(int k = i; k < j+1; k++)
                    {
                        res += arr[k];
                    }
                }
            }
        }
        return res;
    }
};