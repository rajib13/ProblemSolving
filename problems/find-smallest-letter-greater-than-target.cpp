class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0; 
        int length = letters.size();
        int high = length - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(letters[mid]  <= target) low = mid + 1; // If we find the target we are not sure that is the greater (e.g. e, e, e, n). So we need to move right side further.
            else high = mid - 1; 
        }
        return letters[low%length]; 
    }
};
