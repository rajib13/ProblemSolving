class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        int i = 0,  j = 0;
        while(i < name.size() and j < typed.size()){
            if(name[i] == typed[j]){
                i++;
                j++;
            }
            else{
                if(j == 0 || typed[j] != typed[j-1]) return false;
                else j++;
            }
        }
        if(j < typed.size()){
            char ch = typed[j-1];
            while(j < typed.size()) 
                if(ch != typed[j++]) return false;
        }
        return i == name.size();
    }
};

/*
Complexity analysis:
Time: O(n), as we need to scan all chars of typed string, where n is the size of typed.
Space: O(1), since we did not use any extra space in the entire program.
*/
