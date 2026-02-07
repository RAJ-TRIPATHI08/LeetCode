class Solution {
public:
    int minimumDeletions(string s) {
        int del = 0;
        int bcnt = 0;

        for (char ch : s) {
            if (ch == 'b')
                bcnt++;
            else
                del = min(del + 1, bcnt);
        }
        return del;
    }
};