class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while(k > 0) {
            int tem = pq.top();
            pq.pop();
            pq.push(tem+1);
            k--;
        }
        int MOD = 1e9 + 7;
        long long result = 1;
        while(!pq.empty()) {
            result *= pq.top();
            result %= MOD;
            pq.pop();
        }
        return result;
    }
};