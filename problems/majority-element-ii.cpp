class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        /*
             Idea: to be a majority element, a number should have to be present more than third of the array size. That means
             at best two majority elements can be possible. So, we modify the Boyer - Moore algorithm for two possible candidates. 
             At first step we try to find the majority elements and in the second pass we verify that the elements are present more than
             n/3 times.
         */
        
        if(nums.size() == 0) return {}; // edge case
        
        int candidate1 = 0;
        int count1 = 0; 
        int candidate2 = 0; 
        int count2 = 0;
        for(int num : nums){
            if(num == candidate1) count1++;
            else if(num == candidate2) count2++;
            else if(count1 == 0){ 
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0){ 
                candidate2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for(int num : nums){
            if(num == candidate1) count1++;
            else if(num == candidate2) count2++;
        }
        vector<int> ret;
        
        if(count1 > nums.size()/3) ret.push_back(candidate1);
        if(count2 > nums.size()/3) ret.push_back(candidate2);
        
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as we meed to scan every stone at least once.
    Space: O(n), as we use the priority queue of all stones. 
*/
