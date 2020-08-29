class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n), ret;
        for(int i = 0; i < str.size(); i++){
            
            if(i > 0 && (str.size() - i) % 3 == 0)
                ret += ".";
            ret += str[i];
        }
        return ret;
    }
};

/*Complexity analysis:
Time: O(1), since n could be maximum of 10 digits (INT_MAX)
Space: O(1)
*/
