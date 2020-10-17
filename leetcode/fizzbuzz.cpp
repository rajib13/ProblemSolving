class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        
        for(int i = 1; i <= n; i++){
            ret[i-1] = to_string(i);
        }
        
        for(int i = 2; i < n; i += 3){
            ret[i] = "Fizz";
        }
        
        for(int i = 4; i < n; i += 5){
            ret[i] = "Buzz";
        }
        
        for(int i = 14; i < n; i += 15){
            ret[i] = "FizzBuzz";
        }
        
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), as we need to iterate through 1 to n.
    Space: O(1), since we are not using any extra space.
*/
