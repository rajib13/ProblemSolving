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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode* root = head;
        while(head){
            while(head->next and head->val == head->next->val){
                head->next = head->next->next;
            } 
            head = head->next;
        }
        return root; 
    }
};
