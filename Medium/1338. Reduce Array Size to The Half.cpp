class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto i:mp){
           pq.push(make_pair(i.second,i.first)); 
        }
        int cover = 0;
        int count = 0;
        while(cover < arr.size()/2){
            cover += pq.top().first;
            pq.pop();
            count++;

        }
        return count;
    }
};