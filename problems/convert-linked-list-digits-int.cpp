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
            ret = ret * 2 + head->val;
            head = head->next;
        }
        return ret; 
    }
};

/*
    Complexity analysis:   
    Time: O(n), where `n` is the total number of nodes in the given linked list, as we need to scan every node of the list;
    Space: O(1), since we do not use any extra space throughout the entire program;
*/
