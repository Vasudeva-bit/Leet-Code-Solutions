class Solution {
public:
    int bagOfTokensScore(vector<int>& q, int power) {
        sort(q.begin(), q.end());
        int score = 0;
        int max_score = 0;
        int l = 0;
        int r = q.size()-1;
        while(l <= r) {
            if(power >= q[l]) {
                score++;
                power -= q[l];
                l++;
                max_score = max(max_score, score);
            }
            else if(score > 0) {
                score --;
                power += q[r];
                r--;
            }
            else
                break;
        }
        return max_score;
    }
};