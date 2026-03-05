class Solution {
public:
    int minOperations(string s) {
        int flip1 = 0;
        int flip2 = 0;
        int n = s.size();

        for(int i = 0; i < n; i++)
        {
            if(s[i] != (i%2? '1':'0'))
                flip1++;
            
            if(s[i] != (i%2? '0':'1'))
                flip2++;
        }
        cout << s << endl;
        return min(flip1, flip2);
    }
};