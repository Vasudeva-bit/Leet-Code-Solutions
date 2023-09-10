#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* root = head;
        while(head->next != NULL) {
            ListNode* node = new ListNode(__gcd(head->val, head->next->val));
            node->next = head->next;
            head->next = node;
            head = node->next;
        }
        return root;
    }
};