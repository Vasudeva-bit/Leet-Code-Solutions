/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        TreeNode* temp = root;
        while(temp != NULL) {
            if(temp->val > p->val and temp->val > q->val) {
                temp = temp->left;
            } 
            else if(temp->val < p->val and temp->val < q->val) {
                temp = temp->right;
            }
            else
                return temp;
        }
        return NULL;
    }
};