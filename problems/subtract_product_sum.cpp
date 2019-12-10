class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        
        
        while(n > 0){
            int last = n%10;
            product *= last;
            sum += last;
            n /= 10;
            
        }
        
        return product - sum; 
    }
};
