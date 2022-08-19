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
    void dfs(TreeNode* root, unordered_map<int,int>& umap) {
        if(root == NULL)
            return;
        dfs(root->left, umap);
        umap[root->val]++;
        dfs(root->right, umap);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> umap;
        vector<int> result;
        dfs(root, umap);
        int freq = INT_MIN;
        for(auto pair:umap) {
            freq = max(freq, pair.second);
        }
        for(auto pair:umap) {
            if(pair.second == freq)
                result.push_back(pair.first);
        }
        return result;
    }
};