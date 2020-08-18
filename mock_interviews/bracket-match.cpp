int bracketMatch( const string& text ) 
{
  int open = 0; 
  int close = 0;
  for(char ch : text){
    if(ch == '('){
      open++;
    }
    else{
      if(open == 0) close++;
      else open--;
    }
  }
  return open + close;
}

/* Complexity analysis:
 Time: O(n), as we need to scan all character of the given string once.
 Space: O(1), since we do not use any extra space.
*/
