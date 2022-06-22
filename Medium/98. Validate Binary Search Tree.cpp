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
    bool isValidBST(TreeNode* root) {
        return valid(root, -std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
    }
    
    bool valid(TreeNode* root, double left, double right){
        if(root == NULL)
            return true;
        if(!(root->val > left && root->val < right))
            return false;
        return (valid(root->left, left, root->val)&&valid(root->right, root->val, right));
    }
};
