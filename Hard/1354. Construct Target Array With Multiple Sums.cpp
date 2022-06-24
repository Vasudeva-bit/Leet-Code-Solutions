class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long sum = 0;
        for(auto i:target){
            pq.push(i);
            sum += i;
        }
        while(pq.top() != 1){
            int cand = pq.top();
            int rest = sum - cand;
            pq.pop();
            if (rest <= 0 || cand <= rest) return false;
            int prev = cand % rest; // Instead of cand - rest, cand % rest
            // can simplify the computation to direct
            sum -= cand;
            if(sum != 1 && prev == 0) return false;
            sum += prev;
            pq.push(prev);
        }
        return true;
    }
};