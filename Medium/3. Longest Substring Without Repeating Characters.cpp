class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int maxi = 0;
        int l=0;
        int r=0;
        while(r < s.size()){

            char right = s[r++];
            umap[right]++;

            while(umap[right] > 1){
                char left = s[l++];
                umap[left]--;
            }

            maxi = max(maxi, r - l);
        }
        return maxi;
    }
};