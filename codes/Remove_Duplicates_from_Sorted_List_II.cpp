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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        while (pre->next) {
            ListNode *cur = pre->next;
            bool isDup = false;
            while (cur && cur->next) {
                if (cur->val == cur->next->val) {
                    isDup = true;
                    cur = cur->next;
                } else
                    break;
            }

            if (isDup) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};
