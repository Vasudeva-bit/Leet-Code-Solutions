class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> umap;
        for(int i=0;i<order.size();i++) {
            umap[order[i]] += i+1;
        }
        for(int i=1;i<words.size();i++) {
            string one = words[i-1];
            string two = words[i];
            int len = min(one.size(), two.size());
            bool flag = true;
            for(int a=0;a<len;a++) {
                if(umap[one[a]] > umap[two[a]]) {
                    return false;
                }
                else if(umap[one[a]] < umap[two[a]]){
                    flag = false;
                    break;
                }
            }
            if(one.size() > two.size() and flag)
                return false;
        }
        return true;
    }
};