#include "bits/stdc++.h"
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while(curr) {
            n++;
            curr = curr->next;
        }
        int min = n/k;
        int extra = n%k;
        ListNode* prev = NULL;
        vector<ListNode*> out;
        curr = head;
        while(curr) {
            int part = min+(extra>0);
            ListNode* add = curr;
            cout<<part<<endl;
            while(part--) {
                prev = add;
                add = add->next;
            }
            prev->next = NULL;
            out.push_back(curr);
            curr = add;
            extra = max(extra-1, 0);
        }
        while(out.size() < k) out.push_back(NULL);
        return out;
    }
};