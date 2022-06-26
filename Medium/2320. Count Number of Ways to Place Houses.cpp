class Solution {
public:
    int countHousePlacements(int n) {
        if (n == 1)
            return 4;
        long long countS = 1;
        long long countB = 1;
        long long prevS;
        long long prevB;
        for(int i=2;i<=n;i++){
            prevS = countS;
            prevB = countB;
            countS = (prevS + prevB)%1000000007;
            countB = prevS%1000000007;
        }        
        long long result = countS+countB;
        return (result*result)%1000000007;
    }
};