Given a positive integer B denoting the base of a right angled isosceles triangle. Find the maximum number of squares of size 2×2 units that can fit in it.

Input:
First line of input contains an integer T denoting number of test cases. For each test case, there exists one line containing integer B ie-base of right angled isosceles triangle.

Output:
For each test case, print the maximum number of squares that can be fit into the triangle.

Constraints:
1<= T <=100
1<= B <= 1000

Example:

Input:
2
8
2

Output:
6
0



Source code: 
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
	    int n;
	    cin >> n;
	    n = n/2 - 1;
	    cout << n*(n+1)/2 << endl;
	}
	return 0;
}
