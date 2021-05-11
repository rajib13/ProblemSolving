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

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given linked list, as we scan all nodes once. 
    Space: O(1), since we do not use any extra space. 
*/ 
