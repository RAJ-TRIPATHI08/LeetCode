class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string originalText = "";
        int col = encodedText.size()/rows;

        for(int i = 0; i < col; i++)
        {
            for(int j = i; j < encodedText.size(); j += (col+1))
            {
                originalText += encodedText[j];
            }
        }

        while(!originalText.empty() && originalText.back() == ' ')
            originalText.pop_back();

        return originalText;
    }
};