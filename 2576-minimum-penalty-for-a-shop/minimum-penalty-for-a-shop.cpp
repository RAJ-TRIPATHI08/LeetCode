class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int Y = 0;
        for(char c : customers)
            if(c == 'Y')
                Y++;

        auto prefix = [&]() {
            vector<int> pref(n);

            pref[0] = (customers[0] == 'N');

            for(int i = 1; i < n; i++)
            {
                pref[i] = pref[i-1];

                if(customers[i] == 'N')
                    pref[i]++;
            }
            return pref;
        };

        vector<int> pref = prefix();

        auto suffix = [&]() {
            vector<int> suff(n);

            suff[n-1] = (customers[n-1] == 'Y');

            for(int i = n-2; i >= 0; i--)
            {
                suff[i] = suff[i+1];

                if(customers[i] == 'Y')
                    suff[i]++;
            }
            return suff;
        };

        vector<int> suff = suffix();
        int penalty = Y;
        int hr = 0;

        for(int i = 1; i < n; i++)
        {
            if(penalty > suff[i] + pref[i-1])
            {
                hr = i;
                penalty = suff[i] + pref[i-1];
            }
        }

        if(pref[n-1] < penalty)
            hr = n;

        return hr;
    }
};