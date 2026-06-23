class Solution {
public:
    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int _moves = 0;

        for(char c : moves)
        {
            if(c == 'U')
                y++;
            else if(c == 'D')
                y--;
            else if(c == 'L')
                x--;
            else if(c == 'R')
                x++;
            else
                _moves++;
        }

        return abs(0-x) + abs(0-y) + _moves;
    }
};