# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if(not postorder or not inorder):
            return None
        root = TreeNode(postorder[-1])
        mid = inorder.index(postorder[-1])
        print('yes')
        root.left = self.buildTree(inorder[0:mid], postorder[0:mid])
        root.right = self.buildTree(inorder[mid+1:], postorder[mid:-1])
        return root