#include <bits/stdc++.h>
using namespace std;
// tags: C++, Tree, N-arry Tree

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root == NULL) 
            return {};
       vector<int> out;
       out.push_back(root->val);
       for(auto node: root->children) {
           vector<int> vectr = preorder(node);
           out.insert(out.end(), vectr.begin(), vectr.end());
       }
       return out;
    }
};