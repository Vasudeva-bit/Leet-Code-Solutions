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
    map<int, int> l, r, h;
    int height(TreeNode* root) {
        if(!root) return 0;
        int left_h = height(root->left);
        int right_h = height(root->right);
        l[root->val] = left_h;
        r[root->val] = right_h;
        return max(right_h, left_h) + 1;
    }
    void solve(TreeNode* root, int maax, int depth) {
        if(root == NULL)
            return;
        h[root->val] = maax;
        solve(root->left, max(maax, depth+r[root->val]), depth+1);
        solve(root->right, max(maax, depth+l[root->val]), depth+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        solve(root->left, r[root->val], 1);
        solve(root->right, l[root->val], 1);
        vector<int> ans;
        for(auto q:queries)
            ans.push_back(h[q]);
        return ans;
    }
};