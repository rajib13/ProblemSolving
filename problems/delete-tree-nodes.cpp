class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        int count = 0;
        for(int i = nodes - 1; i > 0; i--){
           value[parent[i]] = value[parent[i]] +  value[i];
        }
       
        for(int i = 0; i < value.size(); i++){
            if(value[i] == 0){
                for(int j = 0; j< parent.size(); j++){
                    if(parent[j] == i){
                        value[j] = 0;
                    }
                }
            }
            else count++;
        }
        return count;
    }
};

/*
    Complexity analysis:
    Time: O(mn), where `m` is the value and `n` is the parent size. 
    Space: O(1), since we did not use any auxilary space.
*/
