class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int> > q;        
        for(int i=1;i<heights.size();i++){
            int diff = heights[i]-heights[i-1];
            if(diff > 0){
            if(ladders > q.size()){
                q.push(diff);
            }
            else{
                int brics = diff;
                // check for the use for ladders
                if(q.size() > 0 && q.top() < diff){
                    brics = q.top();
                    q.pop();
                    q.push(diff);
                }
                if(bricks-brics >= 0)
                    bricks -= brics;
                else
                    return i-1;
            }
        }
        }
        return heights.size()-1;
    }
};