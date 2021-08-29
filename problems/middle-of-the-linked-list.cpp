class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return slow;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given linkedlist.
    Space: O(1), since we do not use any extra space.
*/
