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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        
        ListNode *fast = head, *slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 翻转链表
        ListNode *pre = NULL, *cur = slow;
        while (cur != NULL) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        while (pre != NULL) {
            if (pre->val != head->val)
                return false;
            else {
                pre = pre->next;
                head = head->next;
            }
        }
        return true;
    }
};