class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> idx(n);
        iota(begin(idx), end(idx), 0);

        vector<int> res;
        stack<int> st;

        sort(begin(idx), end(idx), [&](int& x, int& y) {
            return positions[x] < positions[y];
        });

        for(int i : idx)
        {
            if(directions[i] == 'R')
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && healths[i] > 0)
                {
                    int topIdx = st.top();
                    st.pop();

                    if(healths[topIdx] > healths[i])
                    {
                        healths[topIdx]--;
                        healths[i] = 0;
                        st.push(topIdx);
                    }
                    else if(healths[topIdx] < healths[i])
                    {
                        healths[i]--;
                        healths[topIdx] = 0;
                    }
                    else
                    {
                        healths[topIdx] = 0;
                        healths[i] = 0;
                    }
                }
            }
        }

        for(int h : healths)
        {
            if(h > 0)
                res.push_back(h);
        }

        return res;
    }
};