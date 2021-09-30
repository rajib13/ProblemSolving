class Solution {
    public int[] sortArrayByParityII(int[] arr) {
       int even = 0;
        for (int i = 1; i < arr.length; i += 2) {
            if (arr[i] % 2 == 0) {
                while (arr[even] % 2 == 0)
                    even += 2;

                int temp = arr[even];
                arr[even] = arr[i];
                arr[i] = temp;
            }

        }
        return arr;
    }
}

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as we need to scan every element at least once.
    Space: O(1), since we do not use any extra space. 
*/
