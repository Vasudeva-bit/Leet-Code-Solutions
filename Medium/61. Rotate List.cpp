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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode* root = head;
        int c = 1;
        while(root->next != NULL){
            root = root->next;
            c++;
        }
        k = k%c;
        if(k == 0)
            return head;
        root->next = head;
        root = NULL;
        for(int i=1;i<=c-k-1;i++){
            head = head->next;
        }
        root = head->next;
        head->next = NULL;
        return root;
    }
};