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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (l1 || l2) {
            if (l1 && (!l2 || l1->val <= l2->val)) {
                cur = cur->next = l1;
                l1 = l1->next;
            }

            if (l2 && (!l1 || l2->val <= l1->val)) {
                cur = cur->next = l2;
                l2 = l2->next;
            }
        }
        cur->next = NULL;
        return dummy->next;
    }
};
