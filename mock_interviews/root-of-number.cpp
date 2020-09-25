double root(double x, unsigned int n) 
{
  double low  = 0.0; 
  double high = max(1.0, x);
  double y =  low + (high - low )/2.0;
  double error = 0.0001; 
  
  while(fabs(pow(y,n) - x) > error){ 
    if(pow(y,n) > x) 
       high = y - error; 
    else if(pow(y,n) < x)
        low = y + error;
    else 
           break;
            
    y =  low + (high - low )/2.0;
    
  }
    return y; 
}


/*
Complexity analysis:
Time: O(log (xn)), where log(x) is for using the pow functoin and O(logn) for the binary search.
Space: O(1), since we did not use any extra space throughut the entire program.
*/
