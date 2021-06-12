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
    Complexity analysis:
    Time: O(nlogn), where `n` is the length of the given string, as we need to scan every character of the string once.
    Space: O(n), since we use a map and heap to store the frequency of the characters. 
*/
