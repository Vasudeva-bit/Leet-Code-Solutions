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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tem = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i=0;i<left-1;i++){
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* connect = prev;
        ListNode* tail = curr;
        
        for(int i=0;i<right-left+1 && curr!= NULL;i++) {
            tem = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tem;
        }
        
        if(connect != NULL)
            connect->next = prev;
        else
            head = prev;
        
        tail->next = curr;
        
        return head;
    }
};