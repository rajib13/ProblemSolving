class Solution {
public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> myMap = new HashMap<>(); //map to store pairs
        for(int i = 0; i < nums.length; i++){
            int subtract = target - nums[i]; //get the difference between target and the current nums[i] value
            if(myMap.containsKey(subtract)){ // check the difference is in the map or not
                return new int[]{myMap.get(subtract), i}; // find out the index of the difference value
            }
            else{
                myMap.put(nums[i], i);
            }
        }
        return new int[]{};
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as we iterate over the entire array once.
    Space: O(n), since we use a hashmap to store the postion of numbers. 
*/
