class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));

        int i = 0, j = tokens.size() - 1;

        int maxScore = 0, score = 0;

        while (i <= j) 
        {
            // Face up
            if (power >= tokens[i]) 
            {
                power -= tokens[i];
                score++;

                maxScore = max(maxScore, score);
                i++;
            }

            // Face down
            else if (score >= 1) 
            {
                power += tokens[j];
                score--;
                j--;
            }

            // No possible move
            else 
            {
                break;
            }
        }

        return maxScore;
    }
};