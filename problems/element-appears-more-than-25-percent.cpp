class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int j = arr.size()  * 0.25;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == arr[i+j]) return arr[i];
        }
        return 0;
    }
};

/*Approach 1 : O(n) time and O(n) space complexity.

    class Solution {
    public:
        int findSpecialInteger(vector<int>& arr) {
            int sz = arr.size();
            vector<int> f(100001,0);

            for(int i = 0; i < sz; i++){
                f[arr[i]]++;
                if(f[arr[i]] > sz/4) return arr[i];
            }
            return arr[sz - 1];
        }
    };

*/
