
int getMinElement(vector<int>& nums, int i, int k){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
  for(int j = i; j <= k; j++){
    minHeap.push(make_pair{nums[j], j});
  }
  
  return minHeap.top().second;
}

vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{
  vector<int> nums = arr;
  for(int i = 0; i < nums.size(); i++){
      int j = getMinElement(nums,i, k);
      swap(nums[i], nums[j]);
  }
  return nums;
}

/*5. Complexity Analysis:
Time: O(nlogk), since for every element we are finding the minimum element in the next k elements.
Space: O(k), since we need to store k elements in the min heap.
*/
