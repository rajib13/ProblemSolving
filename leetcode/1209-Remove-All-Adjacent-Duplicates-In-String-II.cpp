class Solution {
public:
    string removeDuplicates(string str, int k) {
        
        string ret; // return string
        vector<int> count; // we can use vector same as stack.
        
        for(char ch : str){
            if(count.empty() || ch != ret.back()){ // only when the stack in empty and last character does not match.
                count.push_back(ret.size()); // Be careful, we only store the size of the return string
            }
            ret.push_back(ch); // In every case, we keep track of each character storing our return string
            
            
            if(ret.size() - count.back() == k){ // Popping criteria
                ret.erase(count.back()); // erase everything after the given position to the erase() function.
                count.pop_back(); // pop the latest count of return string size.
            }
        }
        return ret;
        
        
    }
};

/*Test Cases: 

"abcd"
2
"deeedbbcccbdaa"
3
"pbbcggttciiippooaais"
2

*/
