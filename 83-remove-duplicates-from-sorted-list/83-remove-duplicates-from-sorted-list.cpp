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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* H = new ListNode(-1e9);
        ListNode* T = H;
        ListNode* curr = head;
        
        while (curr) {
            if (curr->val > T->val) {
                T->next = new ListNode(curr->val);
                T = T->next;
            }
            curr = curr->next;
        }
        
        return H->next;
    }
};