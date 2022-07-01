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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* oddH = odd;
        ListNode* evenH = even;
        bool flag = true;
        while(head != NULL)  {
            if(flag) {
                odd->next = head;
                odd = odd->next;
            }
            else {
                even->next = head;
                even = even->next;
            }
            flag = !(flag);
            head = head->next;
        }
        even->next = NULL;
        odd->next = evenH->next;
        return oddH->next;
    }
};