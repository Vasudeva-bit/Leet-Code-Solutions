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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int n = 0;
        TreeNode* cur = root;
        while(cur != NULL || !(st.empty())){
            while(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            n++;
            if(n == k)
                return cur->val;
            cur = cur->right;
        }
        return 0;
    }
};