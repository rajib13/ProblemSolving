int calcDroneMinEnergy( const vector<vector<int>>& route ) 
{
  int maxHeight = route[0][2]; 
  
  for(int i = 1; i  < route.size(); i++){
    if(route[i][2] > maxHeight)
      maxHeight = route[i][2];
  }
  return maxHeight - route[0][2]; 
}
/*
Complexity analysis:
Time: O(n), as we scanned all point in the route once.
Space: O(1), since we did not use any extra space.

*/
