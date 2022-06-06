class Solution {
public:
    int fib(int n) {
        int one = 0;
        int two = 1;
        if(n == 0)
            return one;
        if(n == 2 || n == 1)
            return two;
        for(int i=2;i<=n;i++){
            int tem = one + two;
            one = two;
            two = tem;
        }
        return two;
    }
};