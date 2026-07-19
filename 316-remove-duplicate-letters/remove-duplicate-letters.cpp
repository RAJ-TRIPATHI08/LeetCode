class Solve {
public:
    Solve() 
    {

    }

    string smallestSubsequence(string s) {
        int n = s.size();
        string res;
        vector<int> lastSeen(26);

        for(int i = 0; i < n; i++)
            lastSeen[s[i] - 'a'] = i;

        vector<bool> inSt(26, false);
        
        for(int i = 0; i < n; i++)
        {
            char newChar = s[i];

            if(inSt[newChar-'a'])
                continue;

            while(!res.empty() && res.back() > newChar && lastSeen[res.back() - 'a'] > i)
            {
                inSt[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(newChar);
            inSt[newChar - 'a'] = true;
        }

        return res;
    }
};

class Solution {
public:
    string removeDuplicateLetters(string s) {
        Solve* obj = new Solve();
        return obj->smallestSubsequence(s);
    }
};