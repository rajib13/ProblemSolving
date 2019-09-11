/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        
        /*Binary search in Java got TLE, but in C++ 100%. Ternary search in Java 100 and 100%*/
        
        int low = 1;
        int high = n;
        
        while(low <= high){
            int quarter1 = low + (high - low) / 3 ; // 0- 33 %
            int quarter3 = high - (high - low) / 3; // 67- 100 %
            
            int guessReturn1 = guess(quarter1);
            int guessReturn2 = guess(quarter3);
            
            if(guessReturn1 == 0) return quarter1;
            if(guessReturn2 == 0) return quarter3;
            
            else if(guessReturn1 < 0) high = quarter1 - 1;
            else if(guessReturn2 > 0 )  low = quarter3 + 1; 
            else{
                low = quarter1 + 1;
                high = quarter3 - 1;
                
            }
        }
        return n;
    }
}
