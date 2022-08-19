/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* dividN(vector<int>& nums, int l, int r) {
        if(r < l) return NULL;
        int mid = (r-l)/2 + l;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = dividN(nums, l, mid-1);
        node->right = dividN(nums, mid+1, r);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dividN(nums, 0, nums.size()-1);
    }
};