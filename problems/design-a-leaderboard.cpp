class Leaderboard {
    
public:
    vector<int> scores;
    
    Leaderboard() {
        scores.clear();
        scores.resize(10005); // We need to resize the vector every time the constructor being called.
    }
    
    
    void addScore(int playerId, int score) {
        scores[playerId] += score;
        
    }
    
    int top(int K) {

        vector<int> temp = scores;
        /*
         To find out the top element, we need to sort the vector. But in that case we got time limit exceeded for the obvious reason.
         So, the alternate solution is using "nth_element()".
         
         std::nth_element() is an STL algorithm which rearranges the list in such a way such that the element at the nth position is the one which should be at that position if we sort the list.
         
         It is not sorting but it will give us the nth element in the right position if it would be sorted.  That means, the only the nth position is sorted, all elements left side of nth element is lower than the nth element and the all right elements are greater than the nth element but the left and right elements are not sorted. So, if we need first n smallest or n largest numbers then if somehow we can find the nth element in the right position then in right side all elements would be greater and left will be lower. 
         
         For example, vec = {5, 2, 1, 10, 9}
         and if n = 2
         then nth_element(vec.begin(), vec.begin() + n, vec.end()) will give us
         vec = {2, 1, 5, 10 ,9} only 5 is in the right position if the vector would be sorted. So, now if we want to find the smallest 2 elements then we will traverse from the beginning of the vector otherwise from the last. 
         
         Time complexity O(n).
        
        */
        int n = temp.size() - K;
        nth_element(temp.begin(), temp.begin() + n, temp.end());
        
        int topSum = 0;
        for(int i = n; i < temp.size(); i++){
            topSum += temp[i];
            
        }
        return topSum;
    }
    
    void reset(int playerId) {
        scores[playerId] = 0;
        
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
