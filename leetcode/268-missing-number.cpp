class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        /*Approach 3: In approach 1, there could be a overflow. Here we chekced it.*/
        
        int diff = nums.size(); // Crucial to get the length of the array.
        for(int i = 0; i < nums.size(); i++){
            
            diff += i - nums[i];
        }
        return diff;
    }
};


/*Approach 2: XOR operation

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size(); // Crucial, because may be this number will not present in the array.
        
        for(int i = 0; i<nums.size(); i++){
            missing ^= i ^ nums[i]; // Idea: as we know if we xor two times a number it will give us zero. We are given all numbers from 0 to n except one number. So, for any given number and one of the positions will be same as the number and we xored them.
        }
        return missing;
    }
};


Approach 1: Sum method

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int sum = 0; 
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
        }
        int length = nums.size();
        return length*(length + 1)/2 - sum;
    }
};


*/
