class Solution {
public:
    int smallestNumber(int n, int t) {
        string num = to_string(n);
        int product = 1;

        for(char ch : num)
            product *= ch - '0';

        if(product % t == 0)
            return n;

        while(product % t)
        {
            product = 1;
            n++;
            num = to_string(n);
            for(char ch : num)
                product *= ch - '0';
        }
        return n;
    }
};