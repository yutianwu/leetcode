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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            ListNode *next = cur->next->next;
            cur->next->next = next->next;
            next->next = cur->next;
            cur->next = next;
            cur = cur->next->next;
        }
        return dummy->next;
    }
};
