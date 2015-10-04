
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
        reverse(head);
        if (head != NULL)
            head->next = NULL;
        return root;
    }
    
    void reverse(ListNode *head) {
        if (head == NULL)
            return;
        if (head->next == NULL) {
            root = head;
            return;
        }
        reverse(head->next);
        head->next->next = head;
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