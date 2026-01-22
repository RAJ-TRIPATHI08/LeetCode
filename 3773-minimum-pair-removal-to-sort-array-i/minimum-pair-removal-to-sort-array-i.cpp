class Solution {
private:
    int minPairPos(vector<int> &arr)
    {
        int minPair = 1e9;
        int pos = -1;
        int n = arr.size();

        for(int i = 0; i < n-1; i++)
        {
            if(arr[i] + arr[i+1] < minPair)
            {
                minPair = arr[i] + arr[i+1];
                pos = i;
            }
        }
        return pos;
    } 

    void mergePair(vector<int> &arr, int pos)
    {
        arr[pos] += arr[pos+1];
        arr.erase(arr.begin() + pos+1);
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0;

        while(!is_sorted(nums.begin(), nums.end()))
        {
            int minSumPos = minPairPos(nums);
            mergePair(nums, minSumPos);
            res++;
        }
        return res;
    }
};