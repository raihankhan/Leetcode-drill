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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA=headA;
        ListNode *ptrB=headB;
        
        while(ptrA!=ptrB) {
            ptrA=ptrA->next;
            ptrB=ptrB->next;
            if(ptrA==ptrB) return ptrA;
            if(ptrA==NULL) ptrA=headB;
            if(ptrB==NULL) ptrB=headA;
        }
        return ptrA;
    }
};
