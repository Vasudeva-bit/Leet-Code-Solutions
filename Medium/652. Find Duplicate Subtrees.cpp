struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string, int> umap; 
    vector<TreeNode*> out;
    string traverse(TreeNode* root) {
        if(root == NULL)
            return "";
        string s = "(";
        s += traverse(root->left);
        s += to_string(root->val);
        s += traverse(root->right);
        s += ")";
        umap[s]++;
        if(umap[s] == 2)
            out.push_back(root);
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return out;
    }
};