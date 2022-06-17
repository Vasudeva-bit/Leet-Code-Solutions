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
    int cam = 0;
    set<TreeNode*> covered;
    int minCameraCover(TreeNode* root) {
        if(root == NULL) return 0;
        covered.insert(NULL);
        dfs(root, NULL);
        return cam;
        
    }
    
    void dfs(TreeNode* curr, TreeNode* parent){
        if(curr != NULL){
            dfs(curr->left, curr);
            dfs(curr->right, curr);
        if((parent == NULL && covered.find(curr) == covered.end()) ||
           (covered.find(curr->left) == covered.end() || covered.find(curr->right) == covered.end())){
            cam++;
            covered.insert(curr);
            covered.insert(parent);
            covered.insert(curr->left);
            covered.insert(curr->right);
        }
        }
    }
    
};