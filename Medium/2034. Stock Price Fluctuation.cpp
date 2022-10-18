class StockPrice {
public:
    int maxTimestamp;
    // mp to store pairs
    // freq to store the freq
    map<int, int> mp, freq;
    StockPrice() {
        maxTimestamp  = -1;
    }
    void update(int timestamp, int price) {
        if(mp.find(timestamp) != mp.end()) {
            int prev = mp[timestamp];
            freq[prev]--;
            if(freq[prev] == 0)
                freq.erase(prev);
        }
        mp[timestamp] = price;
        freq[price]++;
        if(timestamp > maxTimestamp)
            maxTimestamp = timestamp;
    }
    
    int current() {
        return mp[maxTimestamp];
    }
    
    int maximum() {
        return freq.rbegin()->first;
    }
    
    int minimum() {
        return freq.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */