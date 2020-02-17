//
// Created by mac on 2020/2/17.
//

#include "problem.h"

class ProductOfNumbers {
public:
    ProductOfNumbers() {

    }

    void add(int num) {
        numbers.push_back(num);
    }

    int getProduct(int k) {
        int result = 1;
        for (int i=numbers.size()-k; i<numbers.size(); i++) {
            result = result*numbers[i];
        }
        return result;
    }
private:
    vector<int> numbers;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

