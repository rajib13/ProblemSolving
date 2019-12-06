class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        
        for(int i = nodes - 1; i > 0; i--){
           value[parent[i]] = value[parent[i]] +  value[i];
            
        }
        int count = 0;
        for(int i = 0; i < value.size(); i++){
            if(value[i] == 0){
                for(int j = 0; j< parent.size(); j++){
                    if(parent[j] == i){
                        value[j] = 0;
                    }
                }
            }
            else{
                count++;
            }
        }
        
        return count;
    }
};
