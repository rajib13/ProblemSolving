class Solution {
public:
    bool isUgly(int num) {
    if(num == 0) return false;
    int arr[] = {2,3,5};
    for(int i = 0; i < 3; i++) 
        while(num % arr[i] == 0)
            num /= arr[i];
        
        return num == 1;
    }
};

/*
    Complexity analysis: 
    Time: O(log n), as the `while` runs at most log(n) times for 2, 3, 5
    Space: O(1), since we do not use any extra space
*/
