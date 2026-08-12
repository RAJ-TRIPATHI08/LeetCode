class MyHashMap {
public:
    vector<int> A;
    MyHashMap() {
        A.resize(1e6+1, -1);
    }
    
    void put(int key, int value) {
        A[key] = value;
    }
    
    int get(int key) {
        return A[key];
    }
    
    void remove(int key) {
        A[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */