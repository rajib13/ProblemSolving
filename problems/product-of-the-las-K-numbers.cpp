class ProductOfNumbers {
public:
	/*Approach: Prefix product like prefix sum and then in constant time get the solution.*/
    vector<int> vec;
    ProductOfNumbers() {
        vec.push_back(1); // Initialy the vector should contain 1 as we are going to implement prefix product algorithm.
    }
    
    void add(int num) {
        if(num == 0){
            vec.clear(); 
            vec.push_back(1); // We start all over again.
        }
        else vec.push_back(vec.back() * num);
    }
    
    int getProduct(int k) {
        int sz = vec.size();
        return sz > k ? vec.back()/vec[(sz - 1) - k] : 0; // if in last k numbers there is/are a zero(s) then we simply return 0
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
