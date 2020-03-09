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
        
        ListNode* ptr1 = head;
        //Counting the total number of nodes
        ListNode* ptr2 = head;
        while(ptr2){
            ptr2 = ptr2->next;
            len++;
            if(len > n){
                ptr1 = ptr1->next;
            }
        }
        cout << ptr1->val << " ";
        ptr1->next = ptr1->next->next;
        return head; 
        
    }
};
