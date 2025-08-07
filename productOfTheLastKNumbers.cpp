class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
       prefix.push_back(1); 
    }
    
    void add(int num) {
        if(num == 0)
        {
            prefix.clear();
            prefix.push_back(1);
        }
        else
        {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) 
    {
        if(k >= prefix.size())
        {
            return 0;
        }
        return prefix[prefix.size()-1] / prefix[prefix.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */