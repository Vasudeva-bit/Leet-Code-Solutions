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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int c = 1;
        
        ListNode* root = head;
        while(root->next != NULL){
            c++;
            root = root->next;
        }
        
        if(n == c)
            return head->next;
        
        root = head;
        for(int i=1;i<=c-n-1;i++){
            root = root->next;
        }
        
        if(root->next == NULL)
            root = NULL;
        else
            root->next = root->next->next;
        
        return head;
    }
};