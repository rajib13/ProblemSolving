
vector<int> moveZerosToEnd(const vector<int>& arr)
{
  vector<int> nums = arr;
  int zeroCount = 0;
  for(int i = 0;  i < nums.size(); i++){
    if(nums[i] == 0)  zeroCount++;
    else{
      nums[i-zeroCount] = nums[i];
      if(zeroCount > 0) nums[i] = 0;
    }
  }
  return nums;
}


/*
Complexity analysis:
Time: O(n),
Space: O(1), since we did not use any extra space
*/
