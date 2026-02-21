class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(char x) {
        int idx = x - 'a';

        if(par[idx] == idx)
            return idx;

        return par[idx] = find(char(par[idx] + 'a'));
    }

    void unionSet(char u, char v) {
        int parU = find(u);
        int parV = find(v);

        if(parU == parV) return;

        if(rank[parU] > rank[parV]) {
            par[parV] = parU;
        }
        else if(rank[parU] < rank[parV]) {
            par[parU] = parV;
        }
        else {
            par[parV] = parU;
            rank[parU]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        par.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i < 26; i++) par[i] = i;

        for(string s:equations)
        {
            if(s[1] == '=')
            {
                unionSet(s[0], s[3]);
            }
        }

        for(string s:equations)
        {
            int a = find(s[0]);
            int b = find(s[3]);
            if(s[1] == '!')
            {
                if(a == b) return false;
            }
        }
        return true;
    }
};