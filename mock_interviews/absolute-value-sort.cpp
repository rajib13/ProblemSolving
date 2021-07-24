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
    Complexity analysis: 
    Time: O(nlogn), where `n` is the number of elements in the given array, as we use the builtin sort with a custom comparison. 
    Space: O(n), the space typically used by compilers in their implementation of sorting operations.
*/  
