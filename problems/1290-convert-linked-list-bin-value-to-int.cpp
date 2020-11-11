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
    int getDecimalValue(ListNode* head) {
        
        int ret = 0;
        while(head){
            ret = ret  * 2 + head->val;
            head = head->next;
        }
        return ret; 
    }
};
/*
    Complexity analysis: 
    Time: 0(n), where n is the number of nodes in the given linked list
    Space: o(1), since we did not use any extra space.
*/
