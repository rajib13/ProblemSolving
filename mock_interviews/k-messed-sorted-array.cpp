
vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{
  vector<int> nums = arr;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  for(int i = 0; i <= k; i++){
    minHeap.push(nums[i]);
  }
  for(int i = 0; i < nums.size(); i++){
      nums[i] = minHeap.top(); minHeap.pop();
      if((i + k + 1 ) < arr.size())
        minHeap.push(nums[i + k + 1]);
  }
  return nums;
}

/*
Complexity Analysis:
Time: O(nlogk), since for every element we are finding the minimum element in the next k elements.
Space: O(k), since we need to store k elements in the min heap.
*/
