#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../include/Product.h"
#include "../include/Customer.h"

using namespace std;

class Sale {
private:
    shared_ptr<Customer> customer;
    vector<pair<shared_ptr<Product>, int>> items;
    double totalAmount;
    double discount;
    double finalAmount;
    string date;

public:
    Sale(shared_ptr<Customer> customer, const string& date);
    
    void addItem(shared_ptr<Product> product, int quantity);
    void calculateTotal(double discountRate);
    
    shared_ptr<Customer> getCustomer() const;
    double getTotalAmount() const;
    double getDiscount() const;
    double getFinalAmount() const;
    string getDate() const;
    vector<pair<shared_ptr<Product>, int>> getItems() const;
};