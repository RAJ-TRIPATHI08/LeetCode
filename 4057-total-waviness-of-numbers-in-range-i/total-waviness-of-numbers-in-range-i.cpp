class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num2 < 100)
            return 0;

        int waviness = 0;
        for(int i = num1; i <= num2; i++)
        {
            string n = to_string(i);
            
            for(int i = 1; i < n.size() - 1; i++)
            {
                cout << n << endl;
                int v = n[i] - '0';
                int prev = n[i-1] - '0';
                int next = n[i+1] - '0';

                if(v > prev && v > next)    // peak
                    waviness += 1;
                else if(v < prev && v < next)   // valley
                    waviness += 1;
            }
        }
        return waviness;
    }
};