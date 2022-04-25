class MyHashSet {
public:
    vector<list<int>> hash;
    int num;
    MyHashSet() {
        num = 15000;
        hash = vector<list<int>>(num, list<int>{});
    }
    
    void add(int key) {
        int index = key%num;
        if(find(hash[index].begin(), hash[index].end(), key) == hash[index].end())
            hash[index].push_back(key);
    }
    
    void remove(int key) {
        int index = key%num;
        auto it = find(hash[index].begin(), hash[index].end(), key);
        if(it != hash[index].end())
            hash[index].erase(it);
    }
    
    bool contains(int key) {
        int index = key%num;
        if(find(hash[index].begin(), hash[index].end(), key) != hash[index].end())
           return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
