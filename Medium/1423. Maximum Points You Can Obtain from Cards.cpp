class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0;
        int r = 0;
        long long result = 0;
        int maax = 0;
        long long sum = accumulate(cardPoints.begin(), cardPoints.end(), 0LL);
        int n = cardPoints.size();
        while(r < n){
            result += cardPoints[r++];
            while(r-l > n-k){
                result -= cardPoints[l++];
            }
            if(r-l == n-k){
                maax = max(int(sum - result), maax);
            }
        }
        return maax;
    }
};