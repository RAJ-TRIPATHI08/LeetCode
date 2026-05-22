class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> freqCnt;
        int res = 0;

        for(int i = lowLimit; i <= highLimit; i++)
        {
            string s = to_string(i);
            int boxNum = 0;
            for(char c : s)
            {
                boxNum += c - '0';
            }
            freqCnt[boxNum]++;
            res = max(res, freqCnt[boxNum]);
        }
        return res;
    }
};