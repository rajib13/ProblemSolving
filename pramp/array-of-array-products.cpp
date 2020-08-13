
vector<long> arrayOfArrayProducts(const vector<int>& arr) 
{
  if(arr.size() < 2) return {};
  vector<long> res(arr.size(), 0);
  
  res[0] = 1; 
  for(int i = 0; i < arr.size()-1; i++){
    res[i+1] = res[i] * arr[i]; 
  }
  
  int prev = 1;
  for(int i = arr.size() - 1; i >= 0; i--){ 
      res[i] *= prev;
      prev *= arr[i];
  }
  return res;
}

/*Complexity analysis:
Time: O(n), as we scanned all elements of the given array at least twice.
Space: O(1), since we did not use any extra space other than the return vector.
*/
