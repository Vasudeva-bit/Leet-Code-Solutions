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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size() > 0){
            TreeNode* rightSide = NULL;
            int queLen = que.size();
            for(int i=0;i<queLen;i++){
                TreeNode* tem = que.front();
                que.pop();
                if(tem != NULL){
                    rightSide = tem;
                    que.push(rightSide->left);
                    que.push(rightSide->right);
                }
            }
            if(rightSide != NULL)
                result.push_back(rightSide->val);
        }
        return result;
    }
};