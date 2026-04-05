class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char, int> mp;

        for(char ch : moves)
            mp[ch]++;

        return abs(mp['L'] - mp['R']) + mp['_'];
    }
};