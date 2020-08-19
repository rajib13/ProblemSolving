
vector<int> findArrayQuadruplet(const vector<int> &arr, int s) 
{
  if(arr.size() < 4) return {};
  vector<int> nums = arr;
  std::sort(nums.begin(), nums.end());
  
  for(int i = 0; i < nums.size()-3; i++){
    for(int j = i + 1; j < nums.size()-2; j++){
      int sum1 = nums[i] + nums[j];
      int k = j + 1;
      int l = nums.size() - 1;
      
      while(k < l){
        int sum2 = nums[k] + nums[l];
        int sum = sum1 + sum2;
        if(sum == s){
          return vector<int>{nums[i], nums[j], nums[k], nums[l]};
        }
        else if(sum  > s) l--;
        else k++;
    }
  }
  return vector<int>{};
}

/*
Complexity analysis:
Time: O(n^3), where n is the size of the arr.
Space: O(1), since we did not use any extra space.
*/
