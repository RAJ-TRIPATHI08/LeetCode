class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        int n = queries.size();
        int m = dictionary.size();
        
        for(string s : queries)
        {
            for(string t : dictionary)
            {
                if(s == t)
                {
                    res.push_back(s);
                    cout << s << endl;
                    break;
                }
                else
                {
                    int l = s.length();
                    int missMatch = 0;

                    for(int k = 0; k < l; k++)
                    {
                        if(s[k] == t[k])
                            continue;
                        else
                            missMatch++;
                    }
                    if(missMatch <= 2){
                        res.push_back(s);
                        break;
                    }
                }
            }
        }
        return res;
    }
};