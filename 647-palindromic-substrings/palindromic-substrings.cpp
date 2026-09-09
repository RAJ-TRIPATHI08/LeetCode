class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<string> vec;

        for(int i = 0; i < n; i++)
        {
            string str;
            for(int j = i; j < n; j++)
            {
                str += s[j];
                vec.push_back(str); 
            }
        }

        int cnt = 0;
        for(int i = 0; i < vec.size(); i++)
        {
            string str = vec[i];
            int st = 0, end = str.size() - 1;
            bool flag = true;
            while(st <= end)
            {
                if(str[st] == str[end])
                {
                    st++;
                    end--;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt++;
        }
        return cnt;
    }
};