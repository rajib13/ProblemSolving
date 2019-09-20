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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;
        
        ListNode* temp = head;
        //Counting the total number of nodes
        while(temp){
            temp = temp->next;
            len++;
        }
        if(len == n) return head->next; //Edge case
        
        temp = head; // Vital, because now temp is pointing to the next node for previous while loop; 
        
        for(int i=1; i< len-n; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head; 
        
    }
};
