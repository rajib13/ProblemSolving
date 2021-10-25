
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> vec; // stores all values to push. The main stack type vector
    vector<int> minStack; // stores the minimum value in each push
    
    MinStack() {}
    
    void push(int value) {
        vec.push_back(value);
        
        int toPush = minStack.empty() || value < minStack.back() ? value : minStack.back();
        minStack.push_back(toPush);      
    }
    
    void pop() {
        vec.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/*
    Complexity analysis:
    Time: O(1), for all operations (e.g., push, pop, top and getMin)
    Space: O(n), where `n` is the number of elements to store in vectors
*/
