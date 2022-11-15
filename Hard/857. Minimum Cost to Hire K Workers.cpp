class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        priority_queue<int, vector<int>> q;
        vector<pair<double, int>> data;
        int n = quality.size();
        for(int i=0;i<n;i++) {
            double ratio = double(wage[i])/quality[i];
            data.push_back({ratio, quality[i]});
        }
        int sum = 0;
        sort(data.begin(), data.end());
        for(int i=0;i<k;i++) {
            q.push(data[i].second);
            sum += data[i].second;
        }
        double capRation = data[k-1].first;
        double minCost = sum*capRation;
        for(int i=k;i<n;i++) {
            capRation = data[i].first;
            if(!q.empty() and q.top() > data[i].second) {
                sum -= q.top();
                q.pop();
                q.push(data[i].second);
                sum += data[i].second;
            }
            minCost = min(minCost, capRation*sum);
        }
        return minCost;
    }
};