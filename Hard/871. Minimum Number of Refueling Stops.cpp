class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int result = 0;
        priority_queue<pair<int, int>> pq;
        int reach = startFuel;
        int prev;
        stations.push_back({target, 0});
        for(auto pair:stations) {
            int pos = pair[0];
            int gas = pair[1];
            reach -= (pos-prev);
            while(!pq.empty() and reach < 0) {
                reach += pq.top().first;
                result++;
                pq.pop();
            }
            if(reach < 0) return -1;
            pq.push(make_pair(gas, pos));
            prev = pos;
        }
        return result;
    }
};