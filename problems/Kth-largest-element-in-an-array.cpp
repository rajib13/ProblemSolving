class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> minHeap;
        
        for(int i = 0; i < nums.size(); i++){
            minHeap.push(nums[i]);
            if(minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};
/*
    Complexity analysis:
    Time: O(nlogk), wehre n is the total number of elements in the vector.
    Space: O(k), since we stored k elements in the min heap.
*/
