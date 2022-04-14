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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode();
        TreeNode* var = new TreeNode(val);
        temp = root;
        while(temp != NULL){
            if(temp->val > val){
                if(temp->left != NULL)
                    temp = temp->left;
                else{
                    temp->left = var;
                    break;
                }
            }
            else if(temp->val < val){
                if(temp->right != NULL)
                    temp = temp->right;
                else{
                    temp->right = var;
                    break;
                }
            }
        }
        if(root != NULL)
        return root;
        else{
            root = var;
            return var;
        }
    }
};
