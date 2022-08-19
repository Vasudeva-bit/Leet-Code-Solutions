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
    ListNode* partition(ListNode* head, int x) {
        ListNode* low = new ListNode();
        ListNode* high = new ListNode();
        ListNode* ltail = low;
        ListNode* htail = high;
        while(head != NULL) {
            if(head->val < x) {
                ltail->next = head;
                ltail = ltail->next;
            }
            else {
                htail->next = head;
                htail = htail->next;
            }
            head = head->next;
        }
        ltail->next = high->next;
        htail->next = NULL;
        return low->next;
    }
};