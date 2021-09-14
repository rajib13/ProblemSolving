class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ret = count(text.begin(), text.end(), 'b');
        ret = min(ret, (int) count(text.begin(), text.end(), 'a'));
        ret = min(ret, (int) count(text.begin(), text.end(), 'l') / 2);
        ret = min(ret, (int) count(text.begin(), text.end(), 'o') / 2);
        ret = min(ret, (int) count(text.begin(), text.end(), 'n'));
        
        return ret; 
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given text, as we need scan all chars of the text several tiems.
    Space: O(1), since we do not use any extra space.
*/
