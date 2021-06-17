class Solution {
public:
    int getKth(int l, int h, int k) {
        vector<pair<int, int>> ret;
        
        for(int i = l; i <= h; i++){
            int count = 0;
            int n = i;
            while(n != 1){
                if(n % 2) n = 3*n+1;
                else n = n/2;
                count++;
            }
            ret.push_back(make_pair(count, i));
        }
        sort(ret.begin(), ret.end());
        
        return ret[k-1].second; 
    }
};

/*
    Complexity analysis:
    Time: O(nlogn), where `n` is the length of the return vector, as we need to sort the elements.
    Space: O(n), since we use the vector as an additional space.
*/


