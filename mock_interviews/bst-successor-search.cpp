Node* findInOrderSuccessor( Node *inputNode )
{
    if(inputNode == nullptr)return nullptr; 
  
    if(inputNode->right){ 
      inputNode = inputNode->right;
      while(inputNode->left)
        inputNode = inputNode->left;
      return inputNode;
    } else { 
      while(inputNode->parent != nullptr && inputNode->parent->key < inputNode->key) 
        inputNode = inputNode->parent; 
      return inputNode->parent; 
    }
  return nullptr;
}


/*
Complexity analysis:
Time: O(logn), when the given tree is balanced, O(n) if the tree is left skewed or right skewed.
Space: O(1), since we did not use any extra space in the entire algorithm.

*/
