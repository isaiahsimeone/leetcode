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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged = new ListNode();
        ListNode* head = merged;
        
        if (!list1 && !list2)
            return NULL;
        
        while (list1 || list2) {
            if (list1 && list2) {
                if (list1->val <= list2->val) {
                    merged->val = list1->val;
                    list1 = list1->next;
                } else {
                    merged->val = list2->val;
                    list2 = list2->next;
                }
            }
            else if (list1 && !list2) {
                merged->val = list1->val;
                list1 = list1->next;
            }
            else if (!list1 && list2) {
                merged->val = list2->val;
                list2 = list2->next;
            }
            if (list1 || list2) {
                merged->next = new ListNode();
                merged = merged->next;
            }
        }
        return head;
    }
};
