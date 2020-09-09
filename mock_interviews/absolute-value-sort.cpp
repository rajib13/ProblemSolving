vector<int> absSort(const vector<int>& arr)
{
    auto comp = [](int a, int b) { 
        if(abs(a) != abs(b))
           return abs(a)  < abs(b); // We need absolute value so that (-1, 2) works fine! 
        return a < b; 
    };
    std::sort(arr.begin(), arr.end(), comp);
}

/*
Complexity Analysis: 
Time: O(nlogn), as we use the builtin sort with a custom comparison. 
Space: O(n), since the sorting algorithm internally takes O(log n) space.
*/ 
