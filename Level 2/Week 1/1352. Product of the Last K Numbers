class ProductOfNumbers {
private:
    vector <int> products;
    int product;
public:
    ProductOfNumbers() {
        products.clear();
        product = 1;
    }
    
    void add(int num) {
       if(num){
            product *= num;
            products.push_back(product);
       }else{
            products.clear();
            product = 1;
       }
    }
    
    int getProduct(int k) {
        if(products.size() < k)
            return 0;
        else if(k == products.size())
            return product;
        else
            return static_cast<int>(products.back() / products[products.size() - 1 - k]);
    }
};
