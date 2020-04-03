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
        ListNode* root = head;
        int nodeCount = 0;
        while(root){
            root = root->next;
            nodeCount++;
        }
        k %= nodeCount;
        if(nodeCount == k || k == 0) return head;
        
        root = head;
        ListNode* prevNode = nullptr;
        
       for(int i = 0; i < nodeCount - k; i++){
            prevNode = root;
            root = root->next;
        }
        prevNode->next = nullptr;
        ListNode* temp = root;
        while(temp->next) temp = temp->next;
        temp->next = head;
        
    
        return root;
    }
};

/*
[1,2,3,4,5]
1
[1,2,3,4,5]
2
[1,2,3,4,5]
3
[1,2,3,4,5]
4
[1,2,3,4,5]
5
[1,2,3,4,5]
6
[1,2,3,4,5]
7
[1,2,3,4,5]
192

*/
