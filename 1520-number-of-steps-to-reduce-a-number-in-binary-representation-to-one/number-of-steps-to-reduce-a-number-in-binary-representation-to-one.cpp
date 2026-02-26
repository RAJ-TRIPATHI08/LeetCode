class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int steps = 0;
        int carry = 0;

        // Traverse from right to left (excluding first bit)
        for(int i = n - 1; i > 0; i--) {
            
            int bit = (s[i] - '0') + carry;

            if(bit == 1) {
                // odd → add 1 (makes it even), then divide
                steps += 2;
                carry = 1;
            } 
            else {
                // even → just divide by 2
                steps += 1;
            }
        }

        // If carry remains, one extra step
        return steps + carry;
    }
};