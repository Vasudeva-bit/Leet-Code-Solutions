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
    unordered_map<ListNode*, int> umap;
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        if(umap[head] > 0)
            return true;
        umap[head] ++;
        return hasCycle(head->next);
    }
};