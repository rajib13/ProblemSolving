class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0; 
        int length = letters.size();
        int high = length - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(letters[mid]  <= target) low = mid + 1; // If we find the target we are not sure that the next element is the greater (e.g. e, e, e, e, n) letter than target. So we need to move right side further.
            else high = mid - 1; 
        }
        return letters[low%length]; 
    }
};

/*
    Complexity analysis:
    Time: O(logn), where `n` is the length of character in the `letters` array, as at every iteration we discard half of the characters from the consideration.
    Space: O(1), since we do not use any extra space.
*/
