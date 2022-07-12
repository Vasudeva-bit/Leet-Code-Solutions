class SmallestInfiniteSet {
public:
    vector<int> set;
    SmallestInfiniteSet() {
        set = vector<int>(1001, 1);
    }
    
    int popSmallest() {
        for(int i=1;i<1001;i++) {
            if(set[i] == 1) {
                set[i] = 0;
                return i;
            }
        }
        return -1;
    }
    
    void addBack(int num) {
        set[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */