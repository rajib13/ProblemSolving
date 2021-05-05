class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int stone : stones){
            maxHeap.push(stone);
        }
        
        while(maxHeap.size() > 1){
            int y = maxHeap.top(); maxHeap.pop();
            int x = maxHeap.top(); maxHeap.pop();
            
            if(x != y) maxHeap.push(y - x);
        }
        return maxHeap.empty() ? maxHeap.top() : 0;
        
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given stones array, as we meed to scan every stone at least once.
    Space: O(n), as we use the priority queue of all stones. 
*/
