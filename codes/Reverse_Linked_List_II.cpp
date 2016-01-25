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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        for (int i = 0; i < m - 1; i++)
            pre = pre->next;

        ListNode* cur = pre->next;
        for (int i = 0; i < n - m; i++) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        return dummy->next;
    }
};
