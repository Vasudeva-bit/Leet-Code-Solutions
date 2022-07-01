class Solution {
public:
    int get_my_square(int n) {
        int squares = 0;
        while(n != 0) {
            squares += (n%10) * (n%10);
            n = n/10;
        }
        return squares;
    }
    bool isHappy(int n) {
        unordered_map<int,int> umap;
        while(umap.find(n) == umap.end()) {
            umap[n] = get_my_square(n);
            n = umap[n];
            if(n == 1) return true;
        }
        return false;
    }
};