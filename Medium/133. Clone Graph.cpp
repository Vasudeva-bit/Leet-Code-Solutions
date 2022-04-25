/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map){
        vector<Node*> neighbor;
        Node* clone = new Node(node->val);
        map[node] = clone;
        for(auto it:node->neighbors){
            if(map.find(it) != map.end())
                neighbor.push_back(map[it]);
            else
                neighbor.push_back(dfs(it, map));
        }
        clone->neighbors = neighbor;
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        if(node == NULL)
            return NULL;
        if(node->neighbors.size() == 0){
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node, map);
    }
};
