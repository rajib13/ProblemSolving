class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        for(string word : strs){
            string temp = word;
            sort(word.begin(), word.end());
            mp[word].push_back(temp);
        }
        vector<vector<string>> ret;
        
        for(auto entry : mp){
            ret.push_back(entry.second);
        }
        return ret;
    }
};