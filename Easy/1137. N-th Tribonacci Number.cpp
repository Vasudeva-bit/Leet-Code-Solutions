class Solution {
public:
    int tribonacci(int n) {
        if(n < 3)
            return min(1, n);
        int one = 0;
        int two = 1;
        int thr = 1;
        for(int i=3;i<=n;i++) {
            int tem1 = two;
            int tem2 = thr;
            thr = one + two + thr;
            one = tem1;
            two = tem2;
        }
        return thr;
    }
};