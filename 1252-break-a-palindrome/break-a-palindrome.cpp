class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1)
            return "";
        bool changed = false;

        int i = 0;
        int j = palindrome.size()-1;

        while(i < j)
        {
            if(palindrome[i] == palindrome[j] && palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                changed = true;
                break;
            }
            i++;
            j--;
        }
        if(!changed)
            palindrome[palindrome.size()-1] = 'b';
        return palindrome;
    }
};