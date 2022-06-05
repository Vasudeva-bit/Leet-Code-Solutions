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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            double sum = 0;
            int len = q.size();
            for(int i=0;i<len;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                sum += node->val;
            }
            result.push_back(sum/len);
        }
        return result;
    }
};