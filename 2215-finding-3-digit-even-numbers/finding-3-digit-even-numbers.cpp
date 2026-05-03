class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for(int d : digits) 
        {
            freq[d]++;
        }

        vector<int> res;

        for(int num = 100; num <= 998; num += 2) 
        {
            int x = num;
            vector<int> cnt(10, 0);

            cnt[x % 10]++; x /= 10;
            cnt[x % 10]++; x /= 10;
            cnt[x % 10]++;

            bool valid = true;
            for(int d = 0; d < 10; d++) 
            {
                if(cnt[d] > freq[d]) 
                {
                    valid = false;
                    break;
                }
            }

            if(valid) 
            {
                res.push_back(num);
            }
        }

        return res;
    }
};