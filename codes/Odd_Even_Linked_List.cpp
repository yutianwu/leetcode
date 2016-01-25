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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = new ListNode(0);
        ListNode *even = new ListNode(0);
        ListNode *po = odd, *pe = even;

        ListNode *cur1 = head, *cur2 = head ? head->next : NULL;
        while (cur1 || cur2) {
            if (cur1) {
                po = po->next = cur1;

                cur1 = (cur1->next && cur1->next->next ? cur1->next->next : NULL);
            }

            if (cur2) {
                pe = pe->next = cur2;
                cur2 = (cur2->next && cur2->next->next ? cur2->next->next : NULL);
            }
        }
        pe->next = NULL;
        po->next = even->next;
        return odd->next;
    }
};
