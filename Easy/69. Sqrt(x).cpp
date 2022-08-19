class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 or x == 1) return x;
        long long int l = 0;
        long long int r = x;
        while(l < r) {
            unsigned long long int mid = (r - l)/2 + l;
            if(mid*mid > x) r = mid;
            else l = mid+1;
        }
        return l-1;
    }
};