class ProductOfNumbers {
public:
    
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(pre_mul.size()==0) pre_mul.push_back(num);
        else pre_mul.push_back(num*pre_mul[pre_mul.size()-1]);

        if(num==0) pre_mul.clear();
    
    int getProduct(int k) {
        if(pre_mul.size()<k) return 0;
        if(pre_mul.size()==k) return pre_mul[pre_mul.size()-1];
        return pre_mul[pre_mul.size()-1]/pre_mul[pre_mul.size()-k-1];
    }
private:
    vector<int> pre_mul;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */