/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (ListNode* l : lists) {
            while (l) {
                min_heap.push(l->val);
                l = l->next;
            }
        }
        
        if (min_heap.empty())
            return NULL;
        
        ListNode* merged = new ListNode();
        ListNode* head = merged;
                
        while (1) {
            merged->val = min_heap.top();
            min_heap.pop();
            if (!min_heap.empty()) {
                merged->next = new ListNode();
                merged = merged->next;
            } else
                break;
        }

        return head;
    }
};
