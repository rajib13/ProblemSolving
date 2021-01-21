class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> values;
        int length = nums.size();
        vector<int> ret(length, 0);
        
        for(int i = 0; i < length; i++){
            int currentTemp = nums[i];
            
            while(!values.empty() and currentTemp > nums[values.top()]){
                int index = values.top(); values.pop();
                ret[index] = i - index;
            }
            values.push(i); // We will keep track of index rather than the element. 
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given nums, as we scan every element of the nums.
    Space: O(n), since we need to store the indices into the stack, and in worst case we might need to store almost all elements.
*/ 
