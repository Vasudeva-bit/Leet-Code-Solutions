class cmp
{
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        return a.first * b.second < a.second * b.first;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        
        for (int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j < arr.size(); ++j)
            {
                pq.push({arr[i], arr[j]});
                
                if (pq.size() > k)
                    pq.pop();
            }

        return {pq.top().first, pq.top().second};
    }
};