/**
    Solution 1: recursively
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* root = NULL;
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next))  return head;
        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    }
};



/**
    Solution 2: iteratively
*/
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode *cur = head, *pre = NULL;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next =  pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
