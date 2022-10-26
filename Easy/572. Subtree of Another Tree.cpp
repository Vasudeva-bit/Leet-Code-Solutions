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
    bool sameTree(TreeNode* one, TreeNode* two) {
        if(!one or !two)
            return one==NULL and two==NULL;
        else if(one->val == two->val) {
            return sameTree(one->left, two->left) and sameTree(one->right, two->right);
        }
        else
            return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
         if(!s){
             return false;
         }   
         else if(sameTree(s,t)){
             return true;
         }
         else{
             return isSubtree(s->left,t) || isSubtree(s->right,t);
         }
   }
};