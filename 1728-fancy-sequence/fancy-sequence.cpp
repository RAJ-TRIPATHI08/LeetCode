class Fancy {
public:
    typedef long long ll;
    vector<ll> seq;
    ll add;
    ll multiply;
    ll M = 1e9 + 7;
    Fancy() {
        add = 0;
        multiply = 1;
    }
    
    ll power(ll a, ll b)
    {
        if(b == 0)
            return 1;
        
        if(b == 1)
            return a;

        ll half = power(a, b/2);
        ll res = (half * half) % M;

        if(b&1)
        {
            res = (res * a) % M;
        }

        return res;
    } 

    void append(int val) {
        ll x = ((val - add) % M + M) * power(multiply, M-2)%M;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc)%M;
    }
    
    void multAll(int m) {
        multiply = (multiply * m)%M;
        add = (add * m)%M;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size())
            return -1;
        
        return (seq[idx] * multiply + add)%M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */