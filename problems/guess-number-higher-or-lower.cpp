// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        
        while(low <= high){
            long mid = ((long) low + high)/2; 
            if(guess(mid) == 0) return mid;
            else if(guess(mid) > 0){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return n;
    }
};


/*
    Complexity analysis:
    Time: O(log n), where `n` is the given number, as everytime we discard the half of the number.
    Space: O(1), since we do not use any extra space. 
*/
