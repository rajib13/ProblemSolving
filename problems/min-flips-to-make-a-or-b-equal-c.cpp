class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        /*First, convert to bit strings.*/
        string A = bitset<32>(a).to_string(); 
        string B = bitset<32>(b).to_string();
        string C = bitset<32>(c).to_string();
    
        int count = 0; 
        for(int i =0 ; i < 32; i++){
            if(C[i] == '1'){ // if C[i] == 1, either A[i] or B[i] is 1 or not, if both of them are 1 that is also works. 
                if(A[i] != C[i] and B[i] != C[i]) count++;
            }
            else{
                if(A[i] != C[i]) count++; // if C[i] == 0 case.
                if(B[i] != C[i]) count++;
            }
        }
        return count;
        
    }
};



