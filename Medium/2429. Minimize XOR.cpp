class Solution {
public:
    int countBits(int n) {
        int c = 0;
        while(n > 0) {
            int rmsb = n&(-n);
            n -= rmsb;
            c++;
        }
        return c;
    }
    int minimizeXor(int num1, int num2) {
        int c = countBits(num2);
        int x = 0;
        for(int i=31;i>=0;i--) {
            if(c > 0 and (num1 & (1 << i))>0) {
                c--;
                x |= (1<<i);
            }
        }
        for(int i=0;i<32;i++) {
            if(c > 0 and (x & (1 << i)) == 0) {
                c--;
                x |= (1<<i);
            }
        }
        return x;
    }
};