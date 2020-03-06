class Solution {
public:
    int maxArea(vector<int>& height) {
        
        /*Two pionter search algorithm. O(n) time and O(1) space algorithm.*/
        int ptr1 = 0;
        int ptr2 = height.size() - 1;
        
        int maxx = 0;
        while(ptr1 < ptr2){
            int area = min(height[ptr1], height[ptr2]) * (ptr2 - ptr1);
            maxx = max(maxx, area);
            
            if(height[ptr1] >= height[ptr2]) ptr2--;
            else ptr1++;
        }
        return maxx;
    }
};
