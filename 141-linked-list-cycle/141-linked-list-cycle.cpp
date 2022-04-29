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
    const int vis = 1e9;
    bool hasCycle(ListNode *head) {
        while (head) {
            if (head->val == vis) return 1;
            head->val = vis;
            head = head->next;
        }
        return 0;
    }
};