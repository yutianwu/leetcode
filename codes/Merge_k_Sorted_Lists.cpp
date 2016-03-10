/**
疏忽点：
1. 默认的是最大堆，没有弄清楚比较条件
2. 在初始入队的时候没有判空
细节的地方还是要注意
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct MinHeap {
    bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result = new ListNode(0);
        ListNode *cur = result;
        priority_queue<ListNode*, vector<ListNode *>, MinHeap> q;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) q.push(lists[i]);
        }

        while (!q.empty()) {
            ListNode *top = q.top();
            q.pop();
            cur = cur->next = top;
            if (top->next)
                q.push(top->next);
        }
        return result->next;
    }
};
