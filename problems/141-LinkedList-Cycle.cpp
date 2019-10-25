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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head; // pointer 1
        ListNode* fast = head; // pointer 2
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true; // Success case
        }
        return false; // In all other cases.
    }
};
