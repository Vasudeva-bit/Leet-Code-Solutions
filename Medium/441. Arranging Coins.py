class Solution {
public:
    int arrangeCoins(int n) {
        int a = n;
        int b = 0;
        while(a > 0) {
            if(a - (b+1) >= 0) {
                b++;
                a -= b;
            }
            else
                break;
        }
        return b;
    }
};