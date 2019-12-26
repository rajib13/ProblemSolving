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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        
        ListNode* root = head; // To return the head of the list
        ListNode* prevNode = head; // prevNode after every iteration.
        ListNode* startNode = nullptr; // Starting node from where we should reverse the list
        ListNode* nodeBeforeStart = nullptr; // previous node of startNode
       
        
        int nodeCount = 0; // To check whethere we reach the position m or n.
        
        while(head){
            nodeCount++;
            
            if(nodeCount == m){ // When we reach startNode to reverse we initialize these variables to make connection later
                nodeBeforeStart = prevNode;
                startNode = head;
            }
            if(nodeCount > m and nodeCount <= n){
                if(nodeCount == n){ // last node to reverse
                    nodeBeforeStart->next = head; // make head connection after reversing 
                    startNode->next = head->next; // tail connection after reversing
                    if(1 == m) root = head; // special case to update the return root
                }
                /* General reversing a list steps */
                ListNode* curr = head->next;
                head->next = prevNode;
                prevNode = head;
                head = curr;
  
            }
            /*If we do not need to reverse, update the prevNode as well.*/
            else{
                prevNode = head;
                head = head->next; 
                
            }
        }
        return root;
        
    }
};
