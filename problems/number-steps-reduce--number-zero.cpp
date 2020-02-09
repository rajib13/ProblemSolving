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
