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
    int result;
    int distributeCoins(TreeNode* root) {
        result = 0;
        if(root == NULL) return 0;
        dfs(root);
        return result;
    }
    int dfs(TreeNode* curr){
        if(curr == NULL) return 0;
        int left = dfs(curr->left);
        int right = dfs(curr->right);
        result += abs(left) + abs(right);
        return curr->val + left + right - 1;
    }
};