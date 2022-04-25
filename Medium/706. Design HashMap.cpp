class MyHashMap {
public:
    vector<int> i;
    MyHashMap() {
        i = vector<int>(1000001, -1);
    }
    
    void put(int key, int value) {
        i[key] = value;
    }
    
    int get(int key) {
        return i[key];
    }
    
    void remove(int key) {
        i[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
