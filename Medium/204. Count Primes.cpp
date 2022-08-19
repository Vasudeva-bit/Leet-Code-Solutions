class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        
        for(int i=2;i*i<n;i++) {
            if(isPrime[i] == 0) continue;
            for(int j=i*i;j<n;j=j+i) {
                isPrime[j] = 0;
            }
        }
        
        int result = 0;
        for(int i=2;i<n;i++) {
            if(isPrime[i] == 1) result++;
        }
        return result;
    }
};