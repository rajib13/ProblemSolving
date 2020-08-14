bool validateIP(const string& ip)
{
   int octet = -1;
   int count = 0; 
   for(char ch : ip){ 
     if(isdigit(ch) == false && ch != '.') return false;
     if(ch == '.'){ 
        if(octet >= 0 && octet < 256) {
        count++;
        octet = -1;
        }
        else return false;
     }
     else{
       if(octet < 0) octet = ch -'0';
        else octet = octet * 10 + ch - '0'; 
     }
  }
  return (octet >= 0 && octet < 256 && count == 3) ? true : false;
}

/*
Complexity Analysis:
 Time : O(n) , where n is the ip length
 Space: O(1), since we do not use any extra space.

*/

