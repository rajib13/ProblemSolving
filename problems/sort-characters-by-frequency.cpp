class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> heap;
        string ret = "";
        
        for(char ch : s){
            map[ch]++;
        }
       
        for(auto m : map){
            heap.push(make_pair(m.second, m.first));
        }
        
        while(!heap.empty()){
            auto temp = heap.top(); heap.pop();
            ret += string(temp.first, temp.second);
        }

        return ret;
    }
};

/*
Second approach: 
*/

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        vector<string> freq(n+1, "");
        string ret = "";
        
        for(char ch : s) map[ch]++;
        
        for(auto item : map){
            char ch = item.first;
            int pos = item.second;
            freq[pos].append(pos, ch);
        }
        
        for(int i = n; i >= 0; i--){
            if(freq[i] != "")
                ret += freq[i];
        }
        return ret;
    }
};
