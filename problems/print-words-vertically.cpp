class Solution {
public:
    vector<string> printVertically(string s) {
        
        vector<string> ret;
        vector<string> words; 
        string temp = "";
        int maxx = -1; 
        for(int i =0 ; i <= s.size(); i++){
            if(s[i] == ' ' or i == s.size()){
                words.push_back(temp);
                int tempSize = temp.size();
                maxx = max(maxx, tempSize);
                temp = "";
            }
            else temp += s[i];
        }
        if(!words.size()) maxx = s.size();
        
        for(int i = 0 ; i < maxx; i++){
            string temp = "";
            for(int j = 0; j < words.size(); j++){
                if(i >= words[j].size()) temp += ' ';
                else temp += words[j][i];
            }
            int tempSize = temp.size();
            while(true){
                if(temp[--tempSize] != ' ') break;
            }
            ret.push_back(temp.substr(0, ++tempSize));
        }
        return ret;
    }
};
