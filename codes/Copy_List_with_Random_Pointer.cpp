/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;

        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *cur = dummy, *p = head;
        map<int, RandomListNode *> table;
        while (p) {
            RandomListNode *node = new RandomListNode(p->label);
            table[p->label] = node;
            cur = cur->next = node;
            p = p->next;
        }

        p = head;
        cur = dummy->next;
        while (p) {
            if (p->random)
                cur->random = table[p->random->label];

            cur = cur->next;
            p = p->next;
        }
        return dummy->next;
    }
};
