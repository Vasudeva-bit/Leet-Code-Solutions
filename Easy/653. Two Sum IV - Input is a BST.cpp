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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> order;
        while(cur != NULL || !(st.empty())){
            while(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            order.push_back(cur->val);
            cur = cur->right;
        }
        int i=0;
        int j=order.size()-1;
        while(i < j){
            if(order[i] + order[j] == k)
                return true;
            if(order[i] + order[j] < k)
                i++;
            if(order[i] + order[j] > k)
                j--;
        }
        return false;
    }
};