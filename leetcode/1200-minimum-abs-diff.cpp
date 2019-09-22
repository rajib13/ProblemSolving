class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        /*Weekly Contest 159. Beats 100% and 100%*/
        
        sort(arr.begin(), arr.end()); //sort the array first
        
        /*Find the minimum difference through the array.*/
        int minn = INT_MAX;
        for (int i = 1; i<arr.size(); i++){
            minn = min(minn, arr[i]-arr[i-1]);
        }
        
        vector< vector<int>> ret;
        /*Insert all min difference pairs into returnning vector*/
        for(int i = 1; i<arr.size(); i++){
            if (arr[i] - arr[i-1] == minn){
                ret.push_back({arr[i-1], arr[i]});
                }
        }
        return ret; 
    }
};
