class Solution {
public:
    int dist(vector<int> a, vector<int> b){
        return pow(a[0]-b[0], 2)+ pow(a[1]-b[1], 2);
   }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s;
        s.insert(dist(p1, p2));
        s.insert(dist(p2, p3));
        s.insert(dist(p3, p4));
        s.insert(dist(p4, p1));
        s.insert(dist(p4, p3));
        s.insert(dist(p1, p3));
        s.insert(dist(p2, p4));
        if(!s.count(0) and s.size() <= 2)
            return 1;
        return 0;
    }
};