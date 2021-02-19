Problem Statement: 

You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.
 

Example 1:

Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output: 
[null,2,null,2,null,3,null,-1]

Explanation: 
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1

class DListNode{
public:
   int value;
   DListNode* head;
   DListNode* tail;
 
   DListNode(int v){
     this->value = v;
     this->head = nullptr;
     this->tail = nullptr;
   }
};

class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            add(nums[i]);
        }
        head = new DListNode(-1);
        tail = new DListNode(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int showFirstUnique() {
        return head->val;
    }
    
    void add(int value) {
        if(hashMap.find(value) == hashMap.end()){
           DListNode* node = new DListNode(value);
           addToList(node);
           hashMap[value] = node; 
        }
        else{
           DListNode* node = hashMap[value];
           hashMap.erase(value);
           removeFromList(node);
        }
    }
private:
    DListNode *head, *tail;
    unordered_map<int, DListNode*> hashMap;
 
    void addToList(DListNode* node){
       node->next = head->next;
       node->prev = head;
       head->next = node;
       node->next->prev = node;
    }
 
   void removeFromList(DListNode* node){
      node->next->prev = node->prev;
      node->prev->next = node->next;
   }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
