class MyCalendar {
public:
    vector<pair<int, int>> calendar;
    MyCalendar() {
        calendar = {{0, 0}, {1e9, 1e9}};
    }
    
    bool book(int start, int end) {
        int l = 0;
        int r = calendar.size()-1;
        while(l <= r) {
            int mid = (r+l)/2;
            if(calendar[mid].first >= end)
                r = mid - 1;
            else if(calendar[mid].second <= start)
                l = mid + 1;
            else
                return false;
        }
        calendar.insert(calendar.begin()+l, make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */