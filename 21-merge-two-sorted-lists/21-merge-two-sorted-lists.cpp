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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (list1 != nullptr || list2 != nullptr) {
            int v1 = list1 == nullptr ? 1e9 : list1->val;
            int v2 = list2 == nullptr ? 1e9 : list2->val;
            (v1 < v2) ? list1 = list1->next : list2 = list2->next;
            ListNode* next = new ListNode(min(v1, v2));
            tail->next = next;
            tail = next;
        }
        return head->next;
    }
};