void drawTree(double x, double y, double len, double depth){
  if (depth == 0) return;
  
  double p1_x = x - len/2;
  double p1_y = y;
  double p2_x = x + len/2;
  double p2_y = y;
  
  
  double A_x = p1_x;
  double A_y = y + len/2;
  double C_x = p1_x;
  double C_y = y - len/2;
  
  
  double B_x = p2_x;
  double B_y = y + len/2;
  double D_x = p2_x;
  double D_y = y - len/2;
  
  len /= sqrt(2);
  
  drawLine(p1_x, p1_y, p2_x, p2_y);
  drawLine(A_x, A_y, C_x, C_y);
  drawLine(B_x, B_y, D_x, D_y);
  
  drawTree(A_x, A_y, len, depth-1);
  drawTree(B_x, B_y, len, depth-1);
  drawTree(C_x, C_y, len, depth-1);
  drawTree(D_x, D_y, len, depth-1);
  
}


/*
Complexity analysis:
Time: O(4^D), where D is the given depth.
Space:  O(D), since the sibling drawTree will not be called before the current one being executed returns. 
*/
