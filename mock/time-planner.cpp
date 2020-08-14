vector<int> meetingPlanner( const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur) 
{
   int slotsASize = slotsA.size();
   int slotsBSize = slotsB.size();
   int p1 = 0; // 1
   int p2 = 0; // 1
  
   while(p1 < slotsASize && p2 < slotsBSize){
     
     int start = max(slotsA[p1][0], slotsB[p2][0]);
     int end = min(slotsA[p1][1], slotsB[p2][1]);
     
      if(start + dur <= end)
        return vector<int> {start, start + dur};
        
      if(slotsA[p1][1] < slotsB[p2][1])
        p1++;
      else 
        p2++;
     
   }
  
  return {};
  
}

/*
Complexity analysis:
Time: O(m+n), where m is the slotsA and n is the slotsB size.
Space: O(1), since we did not use any extra space.
*/
