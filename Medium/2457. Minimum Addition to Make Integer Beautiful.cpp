class Solution {
public:
    long long total(long long n) {
        long long tem = n;
        long long sum = 0;
        while(tem > 0) {
            sum += tem%10;
            tem /= 10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long tem = n;
        long long out = 0;
        int power = 0;
        while(total(tem) > target) {
            while(tem%10 == 0) power++, tem /= 10;
            int toadd = 10 - tem%10;
            tem += toadd;
            out += toadd*(pow(10, power));
        }
        return out;
    }
};