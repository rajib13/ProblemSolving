  int findLargestSmallerKey(int num) {
        int smaller = -1;
        while(root != null){
          if(root.key >= num){ // we are looking for smaller than num
            root = root.left; 
          }
          else{ 
            smaller = root.key; // when the root->val < num, we store it as our result and keep moving right to get the larger smallest value. 
            root = root.right ;
          }
        }
        return smaller >= num ? -1 : smaller; 
    }

/* Complexity analysis: 
  Time: if the given tree is balanced then O(log n), but in case of left or right skewed BST, it would be O(n).
  Space: O(1), throughout the entire algorithm we did not use any extra space.
*/
