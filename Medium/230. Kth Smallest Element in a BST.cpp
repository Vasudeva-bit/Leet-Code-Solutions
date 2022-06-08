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
    vector<int> kth;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return 0;
        kthSmallest(root->left, k);
        if(kth.size() < k)
            kth.push_back(root->val);
        kthSmallest(root->right, k);
        return kth.back();
    }
};