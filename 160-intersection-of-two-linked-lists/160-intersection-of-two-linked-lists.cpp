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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode *a = A, *b = B;
        while(a != b) {
            a = a ? a->next : B;
            b = b ? b->next : A;
        }
        return a;
    }
};