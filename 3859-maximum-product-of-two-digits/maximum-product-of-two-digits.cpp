class Solution {
public:
    int maxProduct(int number) {
        string num = to_string(number);
        int n = num.size();
        
        int p = 0;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                p = max(p, ((num[i] - '0') * (num[j] - '0')));

        return p;
    }
};