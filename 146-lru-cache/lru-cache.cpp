class LRUCache {
private:
    list<int> dll;    // holds key
    unordered_map<int, pair<list<int>::iterator, int>> mp;    // holds key, pair<address, int>
    int cap;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
     // move accessed node to front (most recently used)
    void makeRecentlyUsed(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        int val = mp[key].second;
        makeRecentlyUsed(key);         // move accessed node to front (most recently used)
        return val;
    }
    
    void put(int key, int value) {
        // if keyy is already present then chng value and makeRecentlyUsed
        if(mp.find(key) != mp.end())       
        {
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else
        {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            cap--;
        }

        if(cap < 0)                   // when size exceeded means we pushed a extra so popback
        {
            int delKey = dll.back();
            mp.erase(delKey);
            dll.pop_back();
            cap++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */