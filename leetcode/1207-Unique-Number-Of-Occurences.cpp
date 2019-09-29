class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        
        vector<int> freq (2003, 0); // We declare a frequency array with more than double of the maximum array size. 
        for(int i = 0 ; i < arr.size(); i++)
        {
            freq[1000 + arr[i]]++; // negative elements will be below 1000 and positive will be over 1000.
        }
        set<int> freqSet; // As we are going to determine the unique element. 
        
        int count = 0; // To keep track number of elements we insert into the frequency set. 
        
        for(int i=0; i < 2003; i++){
           if(freq[i] != 0) {
               count++;
               freqSet.insert(freq[i]);
           }
        }
        return freqSet.size() == count; 
        
    }
};

