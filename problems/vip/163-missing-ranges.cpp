class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
     string getRange(long start, long end){
         return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
     }
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<string> ranges;
        
        long prev = long(lower) - 1; // Long casting is very crucial to avoid overflow and underflow. 
        for(int i = 0 ; i <= nums.size(); i++){
            long curr = i == nums.size() ? long(upper)  + 1 : nums[i]; 
            
            if(curr - prev > 1){
                ranges.push_back(getRange(prev + 1, curr - 1));
            }
            prev = curr; 
        }
            return ranges;
        }
};
