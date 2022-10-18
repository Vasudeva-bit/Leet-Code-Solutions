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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* first = slow->next;
        ListNode* second = NULL;
        slow->next = NULL;
        ListNode* tmp = NULL;
        while(first != NULL) {
            tmp = first->next;
            first->next = second;
            second = first;
            first = tmp;
        }
        ListNode* one = head;
        ListNode* two = second;
        while(two != NULL) {
            ListNode* tmp1 = one->next;
            ListNode* tmp2 = two->next;
            one->next = two;
            two->next = tmp1;
            one = tmp1;
            two = tmp2;
        }
    }
};