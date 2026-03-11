class Solution {
public:
    string removeLeadingZeros(string s) {
        int pos = s.find('1'); // first index of '1'

        if (pos == string::npos) // if no '1' exists
            return "0";

        return s.substr(pos);
    }
    int bitwiseComplement(int n) {
        string s = bitset<64>(n).to_string();
        s = removeLeadingZeros(s);
        for (int i = 0; i < s.length(); i++) {
            s[i] == '0' ? s[i] = '1' : s[i] = '0';
        }

        int res = stoi(s, nullptr, 2);
        return res;
    }
};