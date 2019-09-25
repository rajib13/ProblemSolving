class Solution {
    public String addBinary(String a, String b) {
        
        
        StringBuilder ret = new StringBuilder(); // String class in immutable but StringBuilder is mutable.

        int aSize = a.length() - 1;
        int bSize = b.length() - 1;
        int carry = 0;
        int sum = 0;
        
        while(aSize >=0 || bSize >= 0){ // Whichever complete first
            
            if(aSize >= 0) sum += a.charAt(aSize--) - '0';
            if(bSize >= 0) sum += b.charAt(bSize--) - '0';
            sum += carry; 
            ret.append(sum % 2); // add sum to the return string ret.
            carry = sum / 2; 
            sum = 0; // This is very crucial because we declared sum outside of the loop. 
        }
       
        if(carry  != 0) ret.append(carry);  // To make sure there are no carry.
        
        /*Following part is to make sure there are no initial zeros and then reverse the ret.*/
        boolean flag = false;
        String rev = "";
        for(int i = ret.length() - 1; i>=0; i--){
            if(ret.charAt(i) == '1') flag = true;
            if(flag == true) rev += ret.charAt(i);
        }
        
        return rev.length() == 0? "0" : rev; // if a="0" and b= "0" our flag will be always false hence the output would be "", but it should be "0"
        
    }
}

/*Test Cases


"1010"
"1011"
"11111111111111111111111111111111111111111111111111111"
"1"
"000000000000000000000000000000000000000000000000000"
"111"
"111"
"0000000000000000000000000000000"
"11001010100101"
"11010010101"
"1010010101010100101010101"
"0"
"0"
"0"
"000000000000"
"00000000"



*/
