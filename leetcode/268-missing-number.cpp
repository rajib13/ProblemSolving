class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        /*Approach 3: In approach 1, there could be a overflow. Here we chekced it.*/
        
        int result = nums.size(); 
        for(int i = 0; i < nums.size(); i++){
            
            result += i - nums[i];
        }
        return result;
    }
};


/*Approach 2: XOR operation

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size(); // Crucial, because may be this will not present in the array.
        
        for(int i = 0; i<nums.size(); i++){
            missing ^= i ^ nums[i];
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
