class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ret = keysPressed[0];
        int maxDuration = releaseTimes[0];
        
        for(int i = 1; i < keysPressed.size(); i++){
            int duration = releaseTimes[i]  - releaseTimes[i - 1];
            if(duration == maxDuration and keysPressed[i] > ret) ret = keysPressed[i];
            else if(duration > maxDuration){
                maxDuration = duration;
                ret = keysPressed[i];
            }
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given keys, as we need to iterate over the entire keys to find out the slowest.
    Space: O(1), since we do not use any extra space.
*/
