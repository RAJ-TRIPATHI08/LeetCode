class Solution {
  public:
    string reverseVowels(string& s) {
        // code here.
        int i = 0, j = s.size()-1;
        auto isVowel = [&](char ch) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                return true;
            
            return false;
        };
        
        while(i < j)
        {
            if(!isVowel(s[i]))
                i++;
            if(!isVowel(s[j]))
                j--;
            if(isVowel(s[i]) && isVowel(s[j]))
                swap(s[i++], s[j--]);
        }
        return s;
    }
};