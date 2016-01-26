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
    void reorderList(ListNode* head) {
        if (!head) return ;

        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second = slow->next;
        slow->next = NULL;

        ListNode *tail = reverse(second);
        slow = head;
        while (tail) {
            ListNode *tnext = tail->next;
            tail->next = slow->next;
            slow->next = tail;

            tail = tnext;
            slow = slow->next->next;
        }
    }

    ListNode *reverse(ListNode *head) {
        if (!head) return NULL;
        ListNode *pre = NULL, *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
