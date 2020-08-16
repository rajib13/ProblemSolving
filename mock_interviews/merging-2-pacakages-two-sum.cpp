vector<int> getIndicesOfItemWeights( const vector<int>& arr, int limit)
{
  unordered_map<int, int> ump;
  
  for(int i = 0; i < arr.size(); i++){
    if(ump.find(arr[i]) != ump.end())
      return vector<int>{i, ump[arr[i]]};
    ump[limit - arr[i]] = i;
  }
  return vector<int>{};
}


/*Complexity analysis:
Time: O(n), as we need to scan all elements of the array once.
Space: O(n), since we need to store records in the map.
*/
