class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> myMap; //map to store pairs
        
        for(int i=0;i<nums.size();i++){
            int subtract = target - nums[i]; //get the difference between target and the current nums[i] value
            if(myMap.count(subtract)){ // check the difference is in the map or not
                
                return {myMap.at(subtract), i}; // find out the index of the difference value
            }
            else{
                myMap.insert({nums[i],i});
            }
        }
        return {};
        
    }
};
