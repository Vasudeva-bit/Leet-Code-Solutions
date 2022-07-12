class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        int result = 0;
        for(auto it:amount) {
            pq.push(it);
        }
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = pq.top();
        pq.pop();
        
        while(a > 0) {
            if (b > 0 or c > 0)
            {   if(b > 0) {
                    result++;
                    a--;
                    b--;
                }
                if(a > 0 and c > 0) {
                    result++;
                    a--;
                    c--;
                }
            }
            else {
                result += a;
                a = 0;
                break;
            }
            priority_queue<int> pq;
            pq.push(a);
            pq.push(b);
            pq.push(c);
            
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            c = pq.top();
            pq.pop();
        }
        result += abs(b-c);
        int mx = max(b, c);
        result += mx - abs(b-c);
        return result;
    }
};