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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* root = head;
        int c = 0;
        while(root != NULL) {
            c++;
            root = root->next;
        }
        if(c==1) {
            return NULL;
        }
        c = c/2;
        int n = 0;
        root = head;
        while(head != NULL) {
            if(n == c-1) {
                head->next = head->next->next;
            }
            n++;
            head = head->next;
        }
        return root;
    }
};