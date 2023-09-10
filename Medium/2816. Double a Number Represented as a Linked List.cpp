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
    string twice(string str) {
        string out = "";
        int len = str.size();
        bool carry = false;
        for(int i=len-1;i>=0;i--) {
            int num = str[i]-'0';
            num *= 2;
            num += carry;
            carry = num/10;
            num %= 10;
            out = to_string(num)+out;
        }
        if(carry) out = '1'+out;
        return out;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* root = NULL;
        ListNode* curr = head;
        string str = "";
        
        while(curr != NULL) {
            int val = curr->val;
            str += to_string(val);
            curr = curr->next;
        }
        
        int len = str.size();
        str = twice(str);
        
        if(str.size() > len) {
            root = new ListNode(0);
            root->next = head;
            head = root;
        }
        
        curr = head;
        int i = 0;
        while(curr != NULL) {
            curr->val = str[i]-'0';
            curr = curr->next;
            i++;
        }
        return head;
    }
};