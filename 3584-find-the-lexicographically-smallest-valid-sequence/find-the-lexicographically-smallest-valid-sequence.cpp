class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();

        vector<int> last(n);
        int i = n-1, j = m-1;
        while(i >= 0)
        {
            if(j >= 0 && w1[i] == w2[j])
            {
                if(i+1 == n)
                    last[i] = 1;
                else
                    last[i] = last[i+1] + 1;
                j--;
            }
            else
            {
                if(i+1 < n)
                    last[i] = last[i+1];
            }
            i--;
        }

        // for(int l : last)
        //     cout << l << " ";
        
        vector<int> res;
        bool pow = true;
        for(i = 0, j = 0; i < n && j < m; i++)
        {
            if(w1[i] == w2[j])
            {
                res.push_back(i);
                j++;
            }
            else if(pow && (i + 1 < n && last[i+1] >= m - j -1))
            {
                res.push_back(i);
                j++;
                pow = false;
            }
        }

        return (j == m)? res : vector<int>{};
    }
};