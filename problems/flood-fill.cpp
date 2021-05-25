class Solution {
public:
    int startColor = 0; 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        startColor = image[sr][sc];
        if(startColor != newColor)
            dfs(image, sr, sc, newColor); 
        return image;
        
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor){
        if(sr < 0 or sr >= image.size() or sc < 0 or sc >= image[0].size() or image[sr][sc] != startColor)
            return;
        image[sr][sc] = newColor;
        dfs(image, sr, sc + 1, newColor);
        dfs(image, sr, sc - 1, newColor);
        dfs(image, sr + 1, sc, newColor);
        dfs(image, sr - 1, sc, newColor);
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the total number of pixels in the given image.
    Space : O(n), since we use the recursion, in worst case the recursive call stack will take `n` space. 
*/
