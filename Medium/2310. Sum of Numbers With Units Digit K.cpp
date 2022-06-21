class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        for(int i=1;i<=100;i++){
            if((k*i) <= num && (k*i)%10 == num%10)
                return i;
        }
        return -1;
    }
};