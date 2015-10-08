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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *ptr = dummy;
        while (ptr != NULL && ptr->next != NULL) {
            if (ptr->next->val == val) {
                if (ptr->next->next == NULL) 
                    ptr->next = NULL;
                else {
                    ptr->next->val = ptr->next->next->val;
                    ptr->next->next = ptr->next->next->next;
                }
            } else {
                ptr = ptr->next;
            }
        }
        return dummy->next;
    }
};