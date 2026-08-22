class Solution {
public:
    bool checkDivisibility(int n) {
        int dSum = 0;
        int pSum = 1;

        string num = to_string(n);

        for(auto c : num)
        {
            int d = c - '0';
            dSum += d;
            pSum *= d;
        }

        int sum = pSum + dSum;
        cout << sum << endl;
        return !(n % sum);
    }
};