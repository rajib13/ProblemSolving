class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap; //map to store pairs
        for(int i = 0; i < nums.size(); i++){
            int subtract = target - nums[i]; //get the difference between target and the current nums[i] value
            if(myMap.count(subtract)){ // check the difference is in the map or not
                return {myMap.at(subtract), i}; // find out the index of the difference value
            }
            else{
                myMap.insert({nums[i], i});
            }
        }
        return {};
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as we iterate over the entire array once.
    Space: O(n), since we use a hashmap to store the postion of numbers. 
*/
