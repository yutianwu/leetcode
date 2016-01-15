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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(3);
        dummy->next = head;
        ListNode* front = dummy, *back = dummy;
        for (int i = 0; i < n; i++) {
            if (back != NULL) back = back->next;
            else return head;
        }

        while (back != NULL && back->next != NULL) {
            front = front->next;
            back = back->next;
        }
        front->next = (front->next == NULL ? NULL : front->next->next);
        return dummy->next;
    }
};
