There are n tree in a forest. Heights of the trees is stored in array tree[ ]. If ith tree is cut at height h, the wood obtained is tree[i]-h, given that tree[i]>h. If total wood needed is k (not less, neither more) find the height at which every tree should be cut (all trees have to be cut at the same height).

Input:
First line contains number of test cases t. Then t test cases follow. In each test case, first line contains number of elements n. Next line contains n space separated integers. Third line contains k, i.e. wood to be collected. Input will be read by driver code.

Output:
Output will be an integer representing the height at which trees have to be cut. If no such positive integer output can be found, -1 is printed.

Your task:
Your task is to complete the function find_height(). This function takes the array tree[ ], and the integers n and k as arguments and returns the height at which trees have to be cut. If no positive integer value of height is possible, return -1.

Constraints:
T = 100
1 <= n <= 10000
1 <= tree[i] <= 1000
1 <= k <= 107

Example:
Input:
1
5
2 3 6 2 4
4
6
1 7 6 3 4 7
8
Output:
3
4
Explanation:
Test case 1:
Wood collected by cutting trees at 3 height = 0 + 0 + (6-3) + 0 + (4-3) = 4
hence 3 is to be subtracted from all numbers
Note : Since 2 is lesser than 3, nothing gets subtracted from it.

Testcase 2:
Wood collected by cutting trees at 4 height = 0 + (7-4) + (6-4) + 0 + 0 + (7-4) = 8




Source Code:

int find_height(int tree[], int n, int k)
{
    if(k == 0) return -1;    
    sort(tree, tree+n);
    
    int high = INT_MIN;
    for(int i = 0; i < n; i++){
        high = max(tree[i], high);
    }
    
    int low = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        
        int sum = 0;
        for(int i =0; i < n; i++){
            if(tree[i] > mid) sum += tree[i] - mid; 
        }
        if(sum == k) return mid;
        else if(sum > k) low = mid + 1;
        else high = mid - 1;
    }
    
    return -1;
}


