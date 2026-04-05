class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> freq(26);

        for(char ch : moves)
            freq[ch - 'A']++;

        bool vertical = freq['U' - 'A'] - freq['D' - 'A'];
        bool horizontal = freq['L' - 'A'] - freq['R' - 'A'];

        if(vertical == 0 && horizontal == 0)
            return true;
        return false;
    }
};