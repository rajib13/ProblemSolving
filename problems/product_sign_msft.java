// "static void main" must be defined in a public class.

public class Main {
    private static final int PRODUCT_SIGN_ZERO = 0;
    private static final int PRODUCT_SIGN_POSITIVE = 1;
    private static final int PRODUCT_SIGN_NEGATIVE = -1;
    
    public static void main(String[] args) {
        int negativeCount = 0;

        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == 0) return PRODUCT_SIGN_ZERO;
            else if (nums[i] < 0) negativeCount++;
        }
        return ((negativeCount & 1) != 0) ? PRODUCT_SIGN_NEGATIVE : PRODUCT_SIGN_POSITIVE;
    }
}

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as we need to scan every element of the array.
    Space: O(1), since we did not use any extra space throughout the entire program. 
*/
