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
        if(head == nullptr) return head;
        
        // store the head to re-use
        ListNode* root = head; 
        // First, count the number of nodes in the given list
        int nodeCount = 0;
        while(root){
            root = root->next;
            nodeCount++;
        }
        k %= nodeCount;
        if(nodeCount == k || k == 0) return head;
        
        root = head;
        ListNode* prevNode = nullptr;
        // Traverse until k nodes left
       for(int i = 0; i < nodeCount - k; i++){
            prevNode = root;
            root = root->next;
        }
        prevNode->next = nullptr;
        ListNode* temp = root;
        // Lastly, join the tail to the head of the list
        while(temp->next) temp = temp->next;
        temp->next = head;
    
        return root;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given list, as we need to traverse the list at least once.
    Space: o(1), since we do not use any auxiliary space.
*/
