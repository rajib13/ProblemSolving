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
    void deleteNode(ListNode* node) {
        
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};

/*
Complexity Analysis:
Time: O(1), as we only need to know the given node.
Space: O(1), as we do not need to store anything.
*/
