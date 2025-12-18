#pragma once

#include "Product.h"
#include <vector>
#include <memory>

using namespace std;

class Store {
private:
    vector<shared_ptr<Product>> products;
    double discountThreshold;
    double discountRate;

public:
    Store(double threshold, double rate);
    
    void addProduct(shared_ptr<Product> product);
    vector<shared_ptr<Product>> getProducts() const;
    vector<shared_ptr<Product>> findByManufacturer(const string& manufacturer) const;
    
    double calculatePurchase(const vector<pair<shared_ptr<Product>, int>>& items, bool isRegularCustomer) const;
    
    int getTotalQuantitySold() const;
    double getTotalRevenue() const;
    int getProductQuantitySold(const string& productName) const;
    double getProductRevenue(const string& productName) const;
};
