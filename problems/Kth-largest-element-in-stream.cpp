class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int limit = 0;
    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > limit) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > limit) minHeap.pop();
        return minHeap.top();
    }
};

/*
    Complexity analysis:
    Time: O(logk), where k is the number elements in the min-heap.
    Space: O(k), as we store at most k elements in the min-heap.
*/

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
