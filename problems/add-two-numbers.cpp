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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum = 0;
        ListNode* root = new ListNode(0);
        ListNode* curNode = root;
        while(l1 or l2 or sum){ // Sum is crucial because after all nodes adding maybe there will be a carry. 
            if(l1) {
                sum += l1->val; 
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            curNode->next = new ListNode (sum % 10);
            sum /= 10;
            
            curNode = curNode->next;
            
        }
        return root->next;
    }
};

/*
    Complexity analysis:
    Time: O(max(m,n)), where m and n are the sizes of list1 and list2.
    Space: O(1), since we did not use any extra space.
*/
