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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *pre = &dummy;
        int carry = 0;
        for (ListNode *p1 = l1, *p2 = l2; p1 != NULL || p2 != NULL;
                p1 = p1 == NULL ? NULL : p1->next,
                p2 = p2 == NULL ? NULL : p2->next,
                pre = pre->next) {
            int a = p1 == NULL ? 0 : p1->val;
            int b = p2 == NULL ? 0 : p2->val;
            int mod = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            pre->next = new ListNode(mod);
        }
        if (carry != 0) {
            pre->next = new ListNode(carry);
        }
        return dummy.next;
    }
};