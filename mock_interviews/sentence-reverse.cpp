vector<char> reverseWords( const vector<char>& arr ) 
{
    vector<char> ret;
    int wordStart = 0;
    for(int i = arr.size() - 1; i >= 0; i--){
      if(arr[i] != ' ' && wordStart == 0) wordStart = i+1;
      else if(arr[i] == ' '){
          if(wordStart == 0) ret.push_back(' ');
        else{
          for(int j = i+1; j < wordStart; j++)
            ret.push_back(arr[j]);
          ret.push_back(' '); 
          wordStart = 0;
        }
      }
    }  
    if(wordStart > 0){
       for(int j = 0; j < wordStart; j++)
          ret.push_back(arr[j]);
    }
  
  return  ret; 
}

/*
Complexity Analysis:
Time: O(n), as we traversed the whole sentence twice.
Space: O(1), since we did not use any extra space.
*/
