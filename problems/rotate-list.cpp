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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* root = head;
        int nodeCount = 0;
        while(root){
            root = root->next;
            nodeCount++;
        }
        k %= nodeCount;
        
        root = head;
        
       for(int i = 0; i <= k; i++){
            root = root->next;
        }
        ListNode* ret = root->next;
        ListNode* temp = ret;
        while(temp->next) temp = temp->next;
        temp->next = head;
    
        return ret;
    }
};
