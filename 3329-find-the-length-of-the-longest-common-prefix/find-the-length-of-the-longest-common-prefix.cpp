class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> st;
        for(int n : arr1)
        {
            string num = to_string(n);
            string pref = "";
            for(char ch : num)
            {
                pref += ch;
                st.insert(pref);
            }
        }

        int res = 0;
        for(int n : arr2)
        {
            string num = to_string(n);
            string pref = "";

            for(char ch : num)
            {
                pref += ch;
                int len = pref.size();
                if(st.find(pref) != st.end())
                    res = max(res, len);
            }
        }

        return res;
    }
};