
int findBusiestPeriod( const vector<vector<int> >& data) 
{
    int currVisitors = 0; 
    int busiestTime = 0;
    int maxVisitors = INT_MIN;
  
    
    for(int i = 0; i < data.size(); i++){
       int timestamp = data[i][0];
       int newVisitors =  data[i][1];
       int choice = data[i][2];
       
       if(choice == 1){
         currVisitors += newVisitors;
       }
       else{ 
          currVisitors -= newVisitors; 
       }
       if(i < data.size()-1 and timestamp == data[i+1][0]) continue;
      
       if(maxVisitors < currVisitors){
         busiestTime = timestamp;
         maxVisitors = currVisitors;
       }
    }
      
   return busiestTime;
}

/* 
  Complexity analysis
  Time: O(n), as we need to scan all timestamps once. 
  Space: O(1), since we do not use any extra space throughout the entire program.
*/

