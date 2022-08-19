class Solution {
public:
    int mirrorReflection(int p, int q) {
        int m = 1, n = 1;
        while(p*m != q*n) {
            n += 1;
            m = floor((q*n)/p);
        }
        if(n%2 == 0)
            return 2;
        else {
            if(m%2 == 0)
                return 0;
            else
                return 1;
        }
    }
};