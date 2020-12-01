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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                cycle = true;
                break;
            }
            
        }
        
        if(!cycle) return nullptr; // if pos = -1, case. 
        
        /*Let,
        x = the distance from head node to start of the cycle.
        y = from start of the cycle to meeting point of slow and fast pointers.
        z = from meeting point to the start node of the cycle in other way around.
        
        So, the slow pointer covered x + y and fast pointer covered x + 2y + z (because its already walked through the cycle) and fast pointer covered actually twice the distance of the slow pointer.
        
        Mathematically, 2(x + y) = x + 2y + z;
        Therefore, x = z; That means if we again start the slow pointer from the beginning and fast pointer from the meeting point, then they will meet again on the node where the cycle begins.
        */
        
        slow = head;
        
        while(slow != fast){
            fast = fast->next;
            slow = slow->next;
            if(slow == fast) return slow;
        }
        return slow;
        
    }
};

/*
    Complexity analysis:
    Time: O(n), wehre n is the number of nodes in the linked list.
    Space: O(1), since we did not use any extra space.
*/
