class Solution {
public:
    using ll = long long;
    ll maximumHappinessSum(vector<int>& happiness, int k) {
        int dec = 0;

        sort(begin(happiness), end(happiness), greater<int>());
        ll res = 0;
        for(int h : happiness)
        {
            h -= dec;
            cout << h << endl;
            if(h < 0)
                continue;
            
            res += h;
            k--;
            if(k == 0)
                break;
                   
            dec++;
        }
        return res;
    }
};