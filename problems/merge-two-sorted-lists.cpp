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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        ListNode* head3 = new ListNode(0); //Head of the return list 
        ListNode* cur = head3; // To make the return list.
     
        while(head1 and head2){
            if(head1->val < head2->val){
                cur->next = head1;
                head1 = head1->next; 
            }
            else{
                 cur->next = head2;
                 head2 = head2->next;
            }
            cur = cur->next;
        }
        cur->next = head1 ? head1 : head2;
        
        return head3->next; 
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is th length of the longest list.
    Space: O(1), since we do not use any extra space.
*/
