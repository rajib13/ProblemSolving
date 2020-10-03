int convertToLowerCase(int diff){ 
  while(diff < 97)
    diff += 26; 
  return diff;
}

string decrypt( const string& word ) 
{
  if(word.size() == 0) return ""; 
  string ret = "";
  int prev = (int) word[0]; 
  ret += (char) (prev-1); 
  for(int i = 1; i < word.size(); i++){
      int curr = (int) word[i];
      int diff = curr - prev; 
      int lowerAscii = convertToLowerCase(diff);
      ret += (char) lowerAscii; 
      prev = curr;
  }
  return ret;
}

/*
Complexity analysis:
Time: O(n), as we need to scan all chars once.
Space: O(1), since we did not use any extra space throughout the entire program.
*/
