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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // How many nodes
        ListNode* l = head;
        ListNode* original_head = head;
        
        int sz = 0;
        for ( ; l != NULL; l = l->next)
            sz++;
        
        if (n == sz)
            return original_head->next;
        
        /* Walk the list to the element that needs to be removed */ 
        for (int i = 0; i < sz - n - 1; i++)
            head = head->next;
        
        /* Skip the element */
        if (head->next && head->next->next)
            head->next = head->next->next;
        else
            head->next = NULL;
        
        return original_head;
    }
};
