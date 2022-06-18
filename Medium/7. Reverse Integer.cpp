class Solution {
public:
    int reverse(int x) {
        int sign = 1;;
        if(x<0)
            sign = -1;
        int dup = abs(x);
        int rev = 0;
        int temp;
        while(dup > 0){
            temp = dup%10;
            if(INT_MAX/10 < rev || (INT_MAX/10 == rev && temp > 7)) return 0;
            if(INT_MAX/10 < rev || (INT_MAX/10 == rev && temp < -8)) return 0;
            rev = rev*10 + temp;
            dup = dup/10;
        }
        return rev*sign;
    }
};