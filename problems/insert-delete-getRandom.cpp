class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> ump;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(ump.find(val) != ump.end()) return false;
        ump[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(ump.find(val) == ump.end()) return false;
        int pos = ump[val];
        int last = nums.back();
        ump[last] = pos;
        nums[pos] = last;
        nums.pop_back();
        ump.erase(val);
    
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int random = rand() % nums.size();
        return nums[random];
    }
};


/*
    Complexity analysis:
    Time: O(1), all operations take O(1) time to complete as per the problem requirement.
    Space: O(n), since we store the elements in the map and vector.
*/
