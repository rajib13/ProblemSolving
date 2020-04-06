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
        /*Approach : Two pointers search algorithm.*/
        ListNode *ptr1 = head, *ptr2 = head;
        int nodeCount = 0; 
        while(ptr2){
            ptr2 = ptr2->next;
            if(nodeCount > n){ // First, advance the first pointer by n nodes.
                ptr1 = ptr1->next;
            }
            nodeCount++;
        }
        if(n == nodeCount) return head->next; // Edge case, if the first node needs to be deleted.
        ptr1->next = ptr1->next->next;
        return head; 
        
    }
};

/*Complexity Analysis: O(n) time as we need to traverse all link nodes at least once and O(1) space, as we did not use any extra space. */

/*
Test Cases:
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
