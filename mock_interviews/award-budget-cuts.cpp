double findGrantsCap( vector<int> grantsArray, int newBudget ) 
{
  sort(grantsArray.begin(), grantsArray.end());
  int elementCount = grantsArray.size();
  double value = 0;
  for(int i = 0 ; i < grantsArray.size(); i++){
    value = (double) grantsArray[i];
    double totalCost = value * elementCount;
    if(totalCost == newBudget) return value;
    else if(totalCost < newBudget){
      newBudget -= value;
      elementCount--;
    }
    else{
      double ans = (double)newBudget / (double) elementCount;
      return ans;
    }
  }
  return value;
}

/*
Complexity analysis:
Time: O(n log n), sorting the grantsArray takes O(n log n) time which is dominated.
Space: O(1), if we use the heapsort as a built in sort.
*/
