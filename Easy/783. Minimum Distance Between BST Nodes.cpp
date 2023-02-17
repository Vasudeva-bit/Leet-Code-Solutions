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
    vector<int> sort;
    void BSTsort(TreeNode* root) {
        vector<int> out;
        if(root == NULL)
            return;
        BSTsort(root->left);
        sort.push_back(root->val);
        BSTsort(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        BSTsort(root);
        int out = INT_MAX;
        for(int i=0;i<sort.size()-1;i++) {
            out = min(abs(sort[i]-sort[i+1]), out);
        }
        return out;
    }
};