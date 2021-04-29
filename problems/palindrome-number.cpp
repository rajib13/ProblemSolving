class Solution {
public:
      bool isPalindrome(int x) {
          
          /*
              Idea: To avoid the overflow issue of the reversed number, what if we only revert half of the int number? 
              After all, the reverse of the last half of the palindrome should be the same as the first half of the number, 
              if the number is a palindrome. 
              
              How do we know that we have reached the half of the number?
              Answer: when the original number is less than the reversed number, it means we've processed half of the number digits.
              
              O(log_10 (n)) and O(1) space. 
          */
          
          
          /*Check: All negative numbers and a number that has 0 as the last digit are not palindrome. But note that 0 itself is a palindrome. */
          if(x < 0 || (x % 10 == 0 && x != 0)) return false;  
          
          int reverse = 0; 
          
          while(x > reverse){
              reverse = reverse * 10 + x % 10;
              x /= 10;
          }
          
          /*
              To be a palindrome an even digit number (1221), in this line out of while given number and reverse would be same. 
              For odd digit number (121), x would be 1 and reverse would be 12. So to not consider the last digit(2) that is attached now with
              reverse we divide the reverse. That is it. 
          */
          return x == reverse || x == reverse/10; 
      
      }

};

/*
    Complexity analysis:
    Time: O(log10(n)), where `n` is the number we are given. 
    Space: O(1), as we do not use any extra space.
*/

/* Approach 2: For all positive numbers reverse the whole number and then check if the given number and the reverse is same. O(log10 n) and O(1) space. 


    bool isPalindrome(int x) {
        if(x < 0) return false; 
        
        
        long reverse = 0; // Declare it as long because when you will convert the last number of int range (2147483647) in reverse it will overflow. 
        
        int givenX = x; 
        
        while(x>0){
            int lastDigit = x%10;
            
            reverse = reverse*10 + lastDigit;
            x = x/10;
            
        }
        return givenX == reverse ? true : false; 
    }

*/

