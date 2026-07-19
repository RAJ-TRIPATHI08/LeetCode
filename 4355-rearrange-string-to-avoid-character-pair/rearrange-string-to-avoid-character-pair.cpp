class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        if(x > y)
            sort(begin(s), end(s));
        else
            sort(begin(s), end(s), [](char a, char b){
                return a > b;
            });
        return s;
    }
};