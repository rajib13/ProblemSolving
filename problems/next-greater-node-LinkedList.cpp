class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        
        // First get the linked node value into a vector;
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }

        stack<int> stack; // To store the position of the elements
        
        for(int i = 0 ; i < nums.size(); i++){
            // Check whether the current value is larger than the top of stack.
            while(!stack.empty() and nums[i] > nums[stack.top()]){
                nums[stack.top()] = nums[i]; stack.pop();
            }
            stack.push(i); // store the positions
        }
        while(!stack.empty()){
            nums[stack.top()] = 0; stack.pop(); // Assign zero to all larger elements.
        }
        return nums;
        
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given linkedlist, as we need to scan all nodes at least once.
    Space: O(n), as we store the value of nodes into the vector and later the position into the stack.
*/
