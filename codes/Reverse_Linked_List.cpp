
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
        stack<ListNode*> s;
        while (head != NULL) {
            s.push(head);
            head = head->next;
        }
        
        head = NULL;
        if (!s.empty()) {
            head = s.top();
            s.pop();
        }
        ListNode *cur = head;
        while (!s.empty()) {
            ListNode *tmp = s.top();
            s.pop();
            cur->next = tmp;
            cur = tmp;
        }
        if (cur != NULL) 
            cur->next = NULL;
        return head;
    }
};