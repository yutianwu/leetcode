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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;

        int size = 0;
        ListNode *p = head;
        while (p != NULL) {
            size++;
            p = p->next;
        }

        int turns = size / k;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy->next, *pre = NULL;
        ListNode *last = dummy;

        for (int i = 0; i < turns; i++) {
            ListNode *start = cur;
            for (int j = 0; j < k; j++) {
                ListNode *tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }
            last->next = pre;
            last = start;
            last->next = cur;
            pre = NULL;
        }
        return dummy->next;
    }
};
