class Solution {
public:
    int findPoisonedDuration(vector<int>& tS, int duration) {
        int out = 0;
        for(int i=0;i<tS.size()-1;i++) {
            if(tS[i] + duration > tS[i+1])
                out += tS[i+1] - tS[i];
            else
                out += duration;
        }
        return out + duration;
    }
};