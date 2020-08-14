int shiftedArrSearch( const vector<int>& nums, int num ) 
{
   int low = 0; 
   int high = nums.size()-1; 
  
   while(low <= high){ 
     int mid = low + (high - low)/2; 
     if(nums[mid] == num) return mid; 
     else if(nums[mid] > nums[low]){ // left side is sorted
         if(nums[low] <= num && nums[mid] > num) // the condition to find out the number
             high = mid - 1;
         else 
             low = mid + 1;
       }
     else{ // right side is sorted
          if(num > nums[mid] and num <= nums[high])
              low = mid + 1;
          else 
              high = mid - 1;
     }
   }
  return -1;
}

/*Complexity Aanlysis:
Time: O(logn), since at every iteration we are removing half of the elements.
Space: O(1), since we did not use any extra space.
*/
