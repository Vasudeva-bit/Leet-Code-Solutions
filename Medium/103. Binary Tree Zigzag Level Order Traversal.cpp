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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<vector<int>> out;
        out.push_back({root->val});
        queue<TreeNode*> q;
        q.push(root); 
        bool flag = true;
        while(!q.empty()) {
            vector<TreeNode*> vectr;
            while(!q.empty()) {
                auto node = q.front();
                vectr.push_back(node->left);
                vectr.push_back(node->right);
                q.pop();
            }
            vector<int> temp;
            for(auto node: vectr) {
                if(node != NULL) {
                    temp.push_back(node->val);
                    q.push(node);
                }
            }
            if(flag) {
                reverse(temp.begin(), temp.end());
                flag = false;
            }
            else
                flag = true;
            if(temp.size() > 0)
                out.push_back(temp);
        }
        return out;
    }
};