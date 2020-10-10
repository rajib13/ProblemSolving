

int indexEqualsValueSearch(const vector<int> &arr) 
{
   int low = 0;
   int high = arr.size() - 1;
   int ans = -1;
   while(low <= high){ 
       int mid = low + (high - low)/2; 
       if(arr[mid] == mid){
        ans = mid; 
        high = mid - 1;  
       }
       else if(arr[mid] < mid)
          low = mid + 1;
       else high = mid-1; 
     }

   return ans;
}

/*
   Complexity analysis:
   Time : O(logn), at every iteration we discard at least half of the input elements.
   Space: O(1), since in the entire algorithm we did not use any extra space.
*/
