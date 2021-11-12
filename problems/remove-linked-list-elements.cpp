/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* root = head;
        while(head->next){
            if(head->next->val == val) head->next = head->next->next;
            else head = head->next;
            
        }
        return root->val == val ? root->next : root;
    }
};


/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the linked list, as we need to scan every node of the list.
    Space: O(1), since we do not use any extra space. 
*/
