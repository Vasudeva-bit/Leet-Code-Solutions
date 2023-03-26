#include <bits/stdc++.h>
using namespace std;

// Method 1: O(N) space complexity

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> vectr;
    Solution(ListNode* head) {
        ListNode* cur = head;
        while(cur != NULL) {
            vectr.push_back(cur->val);
            cur = cur->next;
        }
    }
    
    int getRandom() {
        return vectr[rand()%vectr.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// Method 2: O(1) space complexity

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
    ListNode* cur = NULL;
    int size;
    Solution(ListNode* head) {
        cur = head;
        size = 1;
        while(cur->next != NULL) {
            cur = cur->next;
            size++;
        }
        cur->next = head;
    }
    
    int getRandom() {
        int i = rand()%size;
        while(i) {
            cur = cur->next;
            i--;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */