int getDifferentNumber( const vector<int>& nums ) 
{
  vector<int> arr = nums;
  int n = arr.size(); 
  // First pass : place the elements to their correct possition.
  for(int i = 0 ; i  < n; i++){
    while(arr[i] < n && arr[arr[i]] != arr[i]){ 
      swap(arr[arr[i]], arr[i]); 
    }
  }
  // second pass : return the result [0,1,2,3]
  for(int i = 0 ; i < n; i++)
    if(i != arr[i])
      return i; 
  return n; 
}

/*Complexity analysis:
Time: O(n), we need to scan all elements of the array at least once.
Space: O(1), since we did not use any extra space in the entire program.
*/
