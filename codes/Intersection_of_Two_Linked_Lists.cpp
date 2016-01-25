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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        // 找出最后节点连成环
        ListNode *last = headB;
        while (last && last->next) {
            last = last->next;
        }
        last->next = headB;

        ListNode *slow =  headA, *fast = headA;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (!fast->next || !fast->next->next) {
            last->next = NULL;
            return NULL;
        }
        slow = headA;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        last->next = NULL;
        return fast;
    }
};
