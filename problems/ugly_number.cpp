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
Time complexity: As we always divide the numbers so the overall time complexity is O(log n)
Space complexity: O(1) as we do not need any extra space. 
*/
