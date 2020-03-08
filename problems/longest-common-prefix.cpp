class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()) return "";
        
        int charCount = INT_MAX;
        int i, j; 
        for(i = 0; i < strs.size() - 1; i++){
            for( j = 0; j < strs[i].size(); j++){
                if(strs[i][j] != strs[i+1][j]){
                    break;
                }
            }
            charCount = min(charCount, j);
        }
        
        return strs[0].substr(0, charCount); 

        
    }
};

/*
Approach 2.
    
            
        if(strs.empty()) return "";
        
        string prefix = "";
        int i = 1;
        while( i <= strs[0].size()){
            prefix = strs[0].substr(0, i);
            for(int j = 1; j < strs.size(); j++){
                
                string temp = strs[j].substr(0, i);
                if(temp != prefix) {
                    return prefix.substr(0, prefix.size()-1);
                }
            }
            
            i++;
        }


        return prefix; 
*/


        
