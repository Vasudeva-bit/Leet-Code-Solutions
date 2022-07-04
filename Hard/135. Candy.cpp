class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> tem(n, 1);
        
        for(int i=1;i<n;i++) {
            if(ratings[i] > ratings[i-1]) {
                tem[i] = max(tem[i], tem[i-1]+1);
            }
        }
        
        for(int i=n-1;i>0;i--) {
            if(ratings[i] < ratings[i-1]) {
                tem[i-1] = max(tem[i-1], tem[i]+1);
            }
        }
        return accumulate(tem.begin(), tem.end(),0);
    }
};