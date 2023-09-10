#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> dfs(int start, int end) {
        vector<TreeNode*> out;
        if(start > end) return {NULL};
        for(int i=start;i<=end;i++) {
            auto left = dfs(start, i-1);
            auto right = dfs(i+1, end);
            for(auto l: left) {
                for(auto r: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    out.push_back(root);
                }
            }
        }
        return out;
    }
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};