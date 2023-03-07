/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* DFS(vector<vector<int>>& grid, int n, int r, int c) {
        bool allSame = true;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[r][c] != grid[r+i][c+j]) {
                    allSame = false;
                    break;
                }
            }
        }
        if(allSame) {
            Node* node = new Node(grid[r][c], true);
            return node;
        }
        n = n/2;
        Node* topLeft = DFS(grid, n, r, c);
        Node* topRight = DFS(grid, n, r, c+n);
        Node* bottomLeft = DFS(grid, n, r+n, c);
        Node* bottomRight = DFS(grid, n, r+n, c+n);
        Node* node = new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        return DFS(grid, grid.size(), 0, 0);
    }
};