class Solution {
    public String addBinary(String a, String b) {
        
        
        StringBuilder ret = new StringBuilder();

        int aSize = a.length() - 1;
        int bSize = b.length() - 1;
        int carry = 0;
        int sum = 0;
        
        while(aSize >= 0 || bSize >= 0){
            
            if(aSize >= 0) sum += a.charAt(aSize--) - '0';
            if(bSize >= 0) sum += b.charAt(bSize--) - '0';
            sum += carry;
            ret.append(sum % 2);
            carry = sum / 2; 
            sum = 0;
        }
       
        if(carry  != 0) ret.append(carry);    
        
        return ret.reverse().toString();
        
    }
}

/*
    Complexity analysis:
    Time: O(max(m,n)), where m and n are the size of string a and b's length, respectively.
    Space: O(1), since we did not use any extra space.

*/
