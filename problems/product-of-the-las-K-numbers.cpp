class ProductOfNumbers {
public:
    vector<int> vec;
    ProductOfNumbers() {
        vec.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            vec.clear(); 
            vec.push_back(1);
        }
        else vec.push_back(vec.back() * num);
    }
    
    int getProduct(int k) {
        int sz = vec.size();
        return sz > k ? vec.back()/vec[(sz - 1) - k] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
