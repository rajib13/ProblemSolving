class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        
        int lowDigit = log10(low) + 1;
        int highDigit = log10(high) + 1;
        
        vector<int> ret;
        for(int k = lowDigit; k < highDigit + 1; k++){
            for(int i = 0; i < str.size() - k + 1; i++){
                int num = stoi(str.substr(i, k));
                if(num <= high and num >= low){
                    ret.push_back(num);
                }
                else if (num > high) 
                    break;
            }
        }
        
        return ret;
        
    }
};
