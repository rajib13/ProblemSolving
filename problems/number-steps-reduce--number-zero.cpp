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
class Solution {
public:
    int numberOfSteps (int num) {
        if(num == 0) return 0; // Edge Case
        
        int bits = log2(num); // number of bits to represent num
        int ones = bitset<32>(num).count(); // number of ones in binary format, because to subtract means there is a one.
        
        return bits + ones;
    }
};
*/
