class Solution {
public:
    vector<int> getRow(int n) {
        if(n == 0) return {1};
        if(n == 1) return {1, 1};
        vector<int> result = {1, 1};
        for(int i=2;i<=n;i++) {
            vector<int> tem(i+1);
            tem[0] = 1;
            for(int j=1;j<i;j++) {
                tem[j] = result[j-1] + result[j]; 
            }
            tem[i] = 1;
            result.resize(i+1);
            result = tem;
        }
        return result;
    }
};