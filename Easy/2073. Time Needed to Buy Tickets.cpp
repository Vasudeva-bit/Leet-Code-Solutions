class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        for(int i=0;i<=k;i++){
            if(tickets[k] <= tickets[i]){
                time += tickets[k];
            }
            else{
                time += tickets[i];
            }
        }
        
        for(int i=k+1;i<tickets.size();i++){
            if(tickets[k] <= tickets[i]){
                time += tickets[k]-1;
            }
            else{
                time += tickets[i];
            }
        }
        return time;
    }
};