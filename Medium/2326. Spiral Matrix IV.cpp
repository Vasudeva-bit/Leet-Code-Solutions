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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        int i, k = 0, l =0;
        while(k<m && l<n) {
            for(i=l;i<n;i++) {
                if(head != NULL) {
                    result[k][i] = head->val;
                    head = head->next;
                }
                else
                    break;
            }k++;
            
            for(i=k;i<m;i++) {
                if(head != NULL) {
                    result[i][n-1] = head->val;
                    head = head->next;
                }
                else
                    break;
            }n--;
            
            if(k<m){
            for(i=n-1;i>=l;i--) {
                if(head != NULL) {
                    result[m-1][i] = head->val;
                    head = head->next;
                }
                else
                    break;
            }
            }m--;
            if(l<n){
            for(i=m-1;i>=k;i--) {
                if(head != NULL) {
                    result[i][l] = head->val;
                    head = head->next;
                }
                else
                    break;
            }
            }l++;
        }
        return result;
    }
};