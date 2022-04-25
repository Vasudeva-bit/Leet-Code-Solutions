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
    vector<int> inor;
    bool isSymmetric(TreeNode* root) {
        TreeNode* right = root->right;
        TreeNode* left = root->left;
        return check(right, left);
    }
    
    bool check(TreeNode* right, TreeNode* left){
        if(right == NULL && left == NULL)
            return true;
        else if(right == NULL || left == NULL)
            return false;
        if(right->val == left->val && check(right->right, left->left) && check(right->left, left->right))
            return true;
        else 
            return false;
    }
};
