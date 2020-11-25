class Solution {
public:
    int trailingZeroes(int num) {
        
        int count = 0;
        /*Idea: Trailing zeroes can only possible with 2 and 5. So it is enough to find out the multiples of 5 because 2 will be more than 5 and as we need both 
        of them, we can just take minimum number of them. 15 = 3  * 5 so there are only one zero, but 25 = 5 * 5, that means there are two zeroes.*/
        
        int i = 5; 
        while(num/i){
            count += num/i;
            i *= 5; 
        }
        return count;
    }
};

/*
    Complexity analysis:
    Time: O(log n), where n is the give num.
    Space: O(1), as we did not use any extra space in the program.
*/
