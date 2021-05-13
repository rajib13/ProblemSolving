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

/*
    Complexity analysis:
    Time: O(n), where `n` is length of the given linked list, as we need to scan every node.
    Space: O(1), since we do not use any extra space. 
*/ 

