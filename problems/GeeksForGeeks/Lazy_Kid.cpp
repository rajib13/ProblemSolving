John's school has been cancelled due to the Corona Pandemic for a few weeks. He is stuck at home and his mother has given him the task of arranging all his tshirts in sorted order. He has N tshirts all of which are denoted by a distinct numeric value. But John is lazy and wants to be done with this task as soon as possible. Help John find a sub array in the given order of tshirts, such that reversing the subarray will be sufficient to arrange all his tshirts in sorted order.

Input:
The first line of input contains the number of testcases T. The first and only line of every testcase contains an integer N for the number of tshirts followed by N space separated integers denoting their current order.

Output: 
Return true if a sorted array is possible otherwise return false.

Your Task:
You don't have to take input. Complete the function SortedArray() that takes array arr and n as parameter and return the true or flase. The printing is done by the driver code.

Constraints:
1<= T <= 50
1 <= N <= 102

Example:
Input:
2
5 1 2 5 4 3
5 1 2 4 5 3
Output:
Yes
No

Explanation:
Testcase 1: Reverse the subarray {5, 4, 3} to get the sorted array {1, 2, 3, 4, 5}.
Testcase 2: No matter what subarray you reverse, the original array will never be sorted.



Source Code: 

bool SortedArray(int arr[], int n) 
{
    int tip = 0; 
    for (int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]) {tip = i; break;}
    }
    int end = tip + (n - tip)/2;
    for(int i = n-1; i >= end; i--) {
        swap(arr[tip++], arr[i]);
    }
    
    for(int i = 0; i < n - 1; i++){
        
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}
