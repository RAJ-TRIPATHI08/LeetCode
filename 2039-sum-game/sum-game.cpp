class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int h = n/2;

        int diff = 0, qL = 0, qR = 0;
        for(int i = 0; i < n; i++)
        {
            if(i < h)
            {
                if(num[i] == '?') 
                    qL++;
                else
                    diff += num[i] - '0';
            }
            else
            {
                if(num[i] == '?')
                    qR++;
                else
                    diff -= num[i] - '0';
            }
        }

        if((qR + qL) & 1)
            return true;

        return diff != 9 * (qR - qL)/2;
    }
};