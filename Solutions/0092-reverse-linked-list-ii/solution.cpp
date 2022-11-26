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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(left>1) {
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
        
        ListNode* pre_connect = prev;
        ListNode* post_connect = curr;
        
        while(right>0) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            right--;
        }
        
        if(pre_connect != NULL) {
            pre_connect->next = prev;
        } else {
            head = prev;
        }
        post_connect->next = curr;
        
        return head;
    }
};


// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
