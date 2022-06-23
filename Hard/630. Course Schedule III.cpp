class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        priority_queue<int> pq;
        int totTime = 0;
        for(auto it:courses){
            pq.push(it[0]);
            totTime += it[0];
            if(totTime > it[1]){
                int maax = pq.top();
                totTime -= maax;
                pq.pop();
            }
        }
        return pq.size();
    }
};