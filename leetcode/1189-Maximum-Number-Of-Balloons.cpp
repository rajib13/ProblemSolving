class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int ret = count(text.begin(), text.end(), 'b'); // 
        
        ret = min(ret, (int) count(text.begin(), text.end(), 'a')); // Casting is must because min() takes two int arguments. 
        ret = min(ret, (int) count(text.begin(), text.end(), 'l') / 2);
        ret = min(ret, (int) count(text.begin(), text.end(), 'o') / 2);
        ret = min(ret, (int) count(text.begin(), text.end(), 'n'));
        
        return ret; 
        
    }
};
