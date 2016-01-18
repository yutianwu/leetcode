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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        // 先求链表长度
        int len = 1;
        ListNode *tail = head;
        while (tail && tail->next) {
            tail = tail->next;
            len++;
        }
        // 先结环，再解环
        tail->next = head;
        for (int i = 0; i < len - k % len; i++) {
            tail = tail->next;
        }
        ListNode *newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }
};
