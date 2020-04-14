class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> maxHeap;
        for(int i = 0; i<stones.size(); i++){
            maxHeap.push(stones[i]);
        }
        
        while(maxHeap.size() > 1){
            int y = maxHeap.top(); maxHeap.pop();
            int x = maxHeap.top(); maxHeap.pop();
            
            if(x != y) maxHeap.push(y - x);
        }
        return maxHeap.size() ? maxHeap.top() : 0;
        
    }
};

/*
Time complexity: O(n), as we need scan every element at least once.
Space complexity: O(n), as we need to store all elements into the priority queue.
*/
