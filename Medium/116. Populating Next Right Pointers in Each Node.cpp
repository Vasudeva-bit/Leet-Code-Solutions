/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == NULL)
            return NULL;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* var = q.front();
                q.pop();
                if(i == n-1)
                    var->next = NULL;
                else
                    var->next = q.front();
                if(var->left != NULL)
                    q.push(var->left);
                if(var->right != NULL)
                    q.push(var->right);
            }
        }
        return root;
    }
};