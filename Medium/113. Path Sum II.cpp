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
    vector<vector<int>> output;
    int tS;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return {};
        tS = targetSum;
        dfs(root, {}, 0);
        return output;
    }
    void dfs(TreeNode* node, vector<int> list, int sum) {
        list.push_back(node->val);
        sum += node->val;
        cout<<sum<<" ";
        if(node->left != NULL) {
            dfs(node->left, list, sum);
        }
        if(node->right != NULL) {
            dfs(node->right, list, sum);
        }
        if(node->left == NULL and node->right == NULL and sum == tS) {
            output.push_back(list);
        }
    }
};