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
        
        for(string str : strNums)
            cout<< str << " ";
        
        if(strNums[0] == "0") return "0"; // if all the array elements are zero.
        
        string ret = "";
        for(string str : strNums){
                ret += str;
        }
        
        return ret;
    }
};


/*Test Cases

[10,2]
[91,3,30,34,5,55,58,54]
[1]
[]
[1,2,4,8,16,32,64,128,256,512]
[16,128]
[16,198]
*/
