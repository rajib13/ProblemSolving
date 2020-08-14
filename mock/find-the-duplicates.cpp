bool binarySearch(const vector<int>& arr2, int num){
  int low = 0; 
  int high = arr2.size()-1;
  while(low <= high){ 
    int mid = low + (high-low)/2; 
    if(arr2[mid] == num) return true;  
    else if(arr2[mid] > num) high = mid -1; 
    else low = mid + 1;
  }
  return false;
}


vector<int> findDuplicates( const vector<int>& arr1, const vector<int>& arr2) 
{
  vector<int> ret;
  for(int num : arr1){ 
    if(binarySearch(arr2, num)) 
      ret.push_back(num);
  }
  return ret;
}

/*
Complexity analysis:
Time: O(N log M), where N is the size of array 1 and M is for array 2.
Space: O(1), since we did not use any extra space throughut the entire program.
*/
