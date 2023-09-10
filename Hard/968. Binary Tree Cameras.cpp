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

#define inf (1<<20)
class Solution {
public:
    map<pair<TreeNode*, pair<bool, bool>>, int> dp;
    int solve(TreeNode* root, bool curr, bool parent) {
        if(root == NULL) {
            if(curr) return inf;
            else return 0;
        }
        if(root->left == NULL and root->right == NULL) {
            if(curr) return 1;
            else {
                if(parent) return 0;
                else return inf;
            }
        }
        if(dp.find({root, {curr, parent}}) != dp.end())
            return dp[{root, {curr, parent}}];
        if(curr) {
            return dp[{root, {curr, parent}}] = 1+min(solve(root->right, 0, 1), solve(root->right, 1, 1)) + min(solve(root->left, 0, 1), solve(root->left, 1, 1));
        }
        else {
            if(parent) {
                return dp[{root, {curr, parent}}] = min(solve(root->right, 0, 0), solve(root->right, 1, 0)) + min(solve(root->left, 0, 0), solve(root->left, 1, 0));
            }
            else {
                int op1 = solve(root->left, 1, 0) + min(solve(root->right, 0, 0), solve(root->right, 1, 0));
                int op2 = solve(root->right, 1, 0) + min(solve(root->left, 0, 0), solve(root->left, 1, 0));
                return dp[{root, {curr, parent}}] = min(op1, op2);
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        dp.clear();
        return min(solve(root, 1, 0), solve(root, 0, 0));
    }
};