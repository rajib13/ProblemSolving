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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        ListNode* head3 = new ListNode(0); //Head of the return list 
        ListNode* cur = head3; // To make the return list.
     
        while(head1 and head2){
            if(head1->val < head2->val){
                cur->next = head1;
                head1 = head1->next; 
            }
            else{
                 cur->next = head2;
                 head2 = head2->next;
            }
            cur = cur->next;
        }
        cur->next = head1 ? head1 : head2;
        
        return head3->next; 
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        if(lists.size() == 1) return lists[0];
        
        ListNode* head = mergeTwoLists(lists[0], lists[1]);
        for(int i = 2; i < lists.size(); i++){
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};

/*
    Complexity analysis:
    Time: O(kn), where `k` is the lists size and `n` is the length of the longest list.
    Space: O(1), since wee do not use any extra space.
*/
