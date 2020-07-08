class Solution {
public:
    string defangIPaddr(string address) {
        string ret;
        for(int i = 0; i < address.size(); i++){
            if(address[i] == '.') ret += "[.]";
            else ret+= address[i];
    
}
        return ret;
        
    }
};
/*
Complexity analysis:
Time: O(n), as we need to scan all elements once.
Space: O(1), since we did not use extra space (the return string is not counted)
*/
