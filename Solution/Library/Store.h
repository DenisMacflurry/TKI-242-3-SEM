#pragma once

#include <vector>
#include <memory>
#include <string>
#include "../include/Database.h"
#include "../include/Product.h"
#include "../include/Customer.h"
#include "../include/Sale.h"

using namespace std;

class Store {
private:
    Database database;
    double discountThreshold;
    double discountRate;

public:
    Store(double threshold, double rate);
    
    void addProduct(shared_ptr<Product> product);
    void addCustomer(shared_ptr<Customer> customer);
    
    vector<shared_ptr<Product>> showAssortment() const;
    vector<shared_ptr<Product>> findByManufacturer(const string& manufacturer) const;
    
    shared_ptr<Sale> makePurchase(const string& customerName, 
                                  const vector<pair<string, int>>& items,
                                  const string& date);
    
    int getQuantitySoldByProduct(const string& productName, 
                                 const string& startDate, 
                                 const string& endDate) const;
    double getRevenueBySingleProduct(const string& productName,
                                     const string& startDate,
                                     const string& endDate) const;
    int getTotalQuantitySold(const string& startDate, const string& endDate) const;
    double getTotalRevenue(const string& startDate, const string& endDate) const;
    
    shared_ptr<Customer> getCustomer(const string& name) const;
};