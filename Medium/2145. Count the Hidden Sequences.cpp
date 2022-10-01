class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mini = 0, maax = 0, sum = 0;
        for(auto diff: differences) {
            sum += diff;
            mini = min(sum, mini);
            maax = max(sum, maax);
        }
        long high = upper - maax;
        long low = lower - mini;
        cout<<high;
        return ((high-low+1)>0)?(high-low+1):0;
    }
};