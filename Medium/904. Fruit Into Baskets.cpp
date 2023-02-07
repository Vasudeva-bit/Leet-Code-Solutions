// Method 1: Using Hash Map
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int out = 0;
        unordered_map<int, int> umap;
        int prev = 0;
        int sum = 0;
        for(int i=0;i<n;i++) {
            umap[fruits[i]]++;
            sum++;
            if(umap.size() == 2)
                out = max(out, sum);
            while(umap.size() > 2) {
                umap[fruits[prev]]--;
                sum--;
                if(umap[fruits[prev]] == 0)
                    umap.erase(fruits[prev]);
                prev++;
            }
        }
        return max(out, sum);
    }
};
// Method 2: Without using Hash Map
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last_count = 1;
        int last = fruits[0];
        int second_last = -1;
        int curMax = 1;
        int out = 0;
        for(int i=1;i<fruits.size();i++) {
            if(fruits[i] == last or fruits[i] == second_last)
                curMax++;
            else
                curMax = last_count+1;
            if(last == fruits[i])
                last_count++;
            else
                last_count = 1;
            if(last != fruits[i]) {
                second_last = last;
                last = fruits[i];
            }
            out = max(out, curMax);
        }
        return max(out, curMax);
    }
};