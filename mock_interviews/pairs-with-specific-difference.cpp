vector<vector<int>> findPairsWithGivenDifference( const vector<int>& nums, int k) 
{
  vector<vector<int>> ret; 
  unordered_set<int> seen;
  for(int num : nums)
    seen.insert(num);
  for(int num : nums){
    int y = num + k; 
    if(seen.find(y) != seen.end()){
      ret.push_back(vector<int>{y, num});
    }
    
  }
  return ret; 
}

/* Complexity analysis:
Time : O(n), as we need scan all elements of the array twice.
Space : O(n), since we are storing all integers into the set.
*/
