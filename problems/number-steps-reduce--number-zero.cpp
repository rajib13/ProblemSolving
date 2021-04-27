class Solution {
public:
    int numberOfSteps (int num) {
	/*Approach 1: Straight forward solution.*/
        int count = 0 ;
        while(num){
            if(num % 2 == 0) num /= 2;
            else num--;
            count++;
        }
        return count;
    }
};

/*
    Complexity analysis:
    Time: O(1), as the given num is an int, the while loop will run a few times. 
    Space: O(1), as we do not use any extra space.
*/
