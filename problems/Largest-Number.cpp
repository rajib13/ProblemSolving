class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";
        
        vector<string> strNums;
        for(int num : nums){
            strNums.push_back(to_string(num));
        }
        // pairwise comparison sort.
        sort(strNums.begin(), strNums.end(), [](string &s1, string &s2){
            return s1 + s2 > s2 + s1;
            }
        );
        
        if(strNums[0] == "0") return "0"; // if all the array elements are zero.
        
        string ret = "";
        for(string str : strNums){
                ret += str;
        }
        
        return ret;
    }
};
/*
    Complexity analysis:
    Time: O(n), where n is the number of elements in the given vector.
    Space: O(n), since we need to store n elements into an auxilary vector of string.
*/
