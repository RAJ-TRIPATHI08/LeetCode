class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s = 0, e = letters.size() - 1;
        int n = letters.size();
        int idx = n;
        
        int mid = 0;
        while(s <= e)
        {
            mid = s + (e-s)/2;
            if(letters[mid] > target)
            {
                idx = mid;
                e = mid - 1;
            }
            else 
            {
                s = mid + 1;
            }
        }
        
        return letters[idx%n];
    }
};