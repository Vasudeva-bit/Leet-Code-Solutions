/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int temp;
    void deleteNode(ListNode* node) {
        if(node->next->next == NULL){
            node->val = node->next->val;
            node->next = NULL;
            return;
        }
        node->val = node->next->val;
        deleteNode(node->next);
    }
};