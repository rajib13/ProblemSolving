vector<int> absSort(const vector<int>& arr)
{
    auto mySort = [](int a, int b) { 
        if(abs(a) != abs(b))
           return abs(a)  < abs(b); // We need absolute value so that (-1, 2) works fine! 
        return a < b; 
    };
    sort(arr.begin(), arr.end(), mySort);
}

/*
    Complexity Analysis: 
    Time: O(nlogn), as we use the builtin sort with a custom comparison. 
    Space: O(n), since the sorting algorithm internally takes O(log n) space.
*/  
