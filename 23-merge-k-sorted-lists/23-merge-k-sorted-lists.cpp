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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for (auto node : lists) {
            while (node) {
                v.emplace_back(node->val);
                node = node->next;
            }
        }
        sort(v.begin(), v.end());
        ListNode* head = new ListNode();
        ListNode* tail = head;
        for (auto val : v) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        return head->next;
    }
};