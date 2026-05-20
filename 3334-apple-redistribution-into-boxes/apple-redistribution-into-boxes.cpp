class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(begin(capacity), end(capacity));
        int apples = 0;
        for(int n : apple)
            apples += n;

        reverse(begin(capacity), end(capacity));
        int cnt = 0;
        for(int n : capacity)
        {
            apples -= n;
            cnt++;
            if(apples <= 0)
                break;
        }

        return cnt;
    }
};