class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int wordCount = 0;
        while(ss >> word){
            wordCount++;
            if(word.find(searchWord, 0) == 0) return wordCount;
        }
        return -1; 
    }
};

/*
    Complexity Analysis:
    Time: O(n), as we need to scan all chars (in worst case) of the given sentence.
    Space: O(1), as we do not use any extra space. 

*/
