class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        string binary = bitset<32>(n).to_string();   
        for(int i = 0; i < 16; i++){
            swap(binary[i], binary[31-i]);
        }
        uint32_t decimal = bitset<32> (binary).to_ulong();
        return decimal;
    }
};

/*
Bit manipulation solution: 

    public int reverseBits(int n) {
        if (n == 0)
            return 0;
        int res = 0;
        for(int i = 0; i < 32; i++){
            //Move all bits to left by 1, so that we can fill the rightmost bit (0) in next step
            res = res << 1;
            
            //Check if rightmost bit is set, if yes then put 1 in the last bit of res 
            if((n & 1) == 1) res = res + 1;
            
            //get the next bit of the number n by shifting bits to the right
            n = n >> 1;
        }
        return res;
    }
*/
