class Solution {
public:
    int side;
    vector<int> matchstickS;
    bool makesquare(vector<int>& matchsticks) {
        int tot = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(tot % 4 != 0) return false;
        side = tot/4;
        matchstickS = matchsticks;
        sort(matchstickS.begin(), matchstickS.end(), greater<int>());
        return dfs(0,0,0,0,0);
    }
    bool dfs(int a, int b, int c, int d, int k) {
        if(k == matchstickS.size()) {
            if(a==b and b==c and c==d) 
                return true;
            return false;
        }
        int m = matchstickS[k];
        if(side >= a+m and dfs(a+m, b, c, d, k+1))
            return true;
        if(side >= b+m and dfs(a, b+m, c, d, k+1))
            return true;
        if(side >= c+m and dfs(a, b, c+m, d, k+1))
            return true;
        if(side >= d+m and dfs(a, b, c, d+m, k+1))
            return true;
        return false;
    }
};