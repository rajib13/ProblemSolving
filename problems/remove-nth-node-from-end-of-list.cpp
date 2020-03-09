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
        
        ListNode *ptr1 = head, *ptr2 = head;
        int nodeCount = 0; 
        while(ptr2){
            ptr2 = ptr2->next;
            if(nodeCount > n){
                ptr1 = ptr1->next;
            }
            nodeCount++;
        }
        if(n == nodeCount) return head->next;
        ptr1->next = ptr1->next->next;
        return head; 
        
    }
};

/*
[1,2,3,4,5]
1
[1,2,3,4,5]
2
[1,2,3,4,5]
3
[1,2,3,4,5]
4
[1,2,3,4,5]
5
*/
