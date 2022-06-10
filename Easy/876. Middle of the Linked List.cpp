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
    ListNode* middleNode(ListNode* head) {
        ListNode* root = head;
        int c = 1;
        while(root->next != NULL){
            root = root->next;
            c++;
        }
            c = c/2;
        root = head;
        for(int i=1;i<=c;i++){
            root = root->next;
        }
        return root;
    }
};