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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) 
            return false;
        return helper(root, targetSum, 0);
    }
    bool helper(TreeNode* root, int targetSum, int target) {
        if(root == NULL) {
            return false;
        }
        target += root->val;
        if(root->left == NULL && root->right == NULL) {
            if(target == targetSum) return true;
        }
        return (helper(root->left, targetSum, target) or helper(root->right, targetSum, target));
    }
};