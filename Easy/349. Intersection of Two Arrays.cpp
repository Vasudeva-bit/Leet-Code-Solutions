class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> result;
        for(int i=0;i<nums1.size();i++) {
            umap[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++) {
            if(umap.find(nums2[i]) != umap.end()) {
                result.push_back(nums2[i]);
                umap.erase(nums2[i]);
            }
        }
        return result;
    }
};