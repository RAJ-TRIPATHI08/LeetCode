class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for(auto c : s)
            freq[c-'a']++;

        string left = "";
        char mid = 0;

        for(int i = 0; i < 26; i++)
        {
            left.append(freq[i]/2, char(i + 'a'));

            if(freq[i] % 2 == 1)
                mid = char(i + 'a');
        }

        string right = left;
        reverse(begin(right), end(right));

        if(mid)
            return left + mid + right;
        
        return left + right;
    }
};