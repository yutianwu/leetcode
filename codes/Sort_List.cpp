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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *headb = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(headb));
    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (head1 || head2) {
            if (head1 &&(!head2 || head1->val <= head2->val)) {
                cur = cur->next = head1;
                head1 = head1->next;
            }

            if (head2 && (!head1 || head2->val <= head1->val)) {
                cur = cur->next = head2;
                head2 = head2->next;
            }
        }
        cur->next = NULL;
        return dummy->next;
    }
};
