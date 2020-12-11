class Solution {
public:
    string twoPointers(string str){
        int i = 0; 
        int j = 0;
        while(i < str.size()){
            if(isalpha(str[i])){
                swap(str[j++], str[i]);
            }
            i++;
        }
        return str;
    }
    
    string replaceLeftCharWithBackspace(string str){
        int n = str.size();
        int j = 0;
        for(int i = n-1; i >= 0; i--){
            if(str[i] == '#'){
                j++;
            }
            else{
                if(j) {
                    str[i] = '#'; 
                    j--;
                }
            }
        }
        return str;
    }
    bool backspaceCompare(string S, string T) {
        
        /*Approach : Two pointers algorithm*/
        int n = S.size();
        S = replaceLeftCharWithBackspace(S);
        S = twoPointers(S);
        while(n > 0 and !isalpha(S[--n])) S.pop_back();
        
        int m = T.size();
        T = replaceLeftCharWithBackspace(T);
        T = twoPointers(T);
        while(m > 0 and !isalpha(T[--m])) T.pop_back();
    
        return S == T;
    }
   
};

/*
    Complexity Analysis:
    Time : O(n), as we need to scan all characters at least once.
    Space : O(1), as we do not use any extra space. 
*/
