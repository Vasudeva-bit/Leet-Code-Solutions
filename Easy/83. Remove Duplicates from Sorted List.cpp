/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        
        ListNode* tem = head;
        while(tem != NULL) {
            while(tem->next != NULL and tem->val == tem->next->val) {
                tem->next = tem->next->next;
            }
            tem = tem->next;
        }
        return head;
    }
};