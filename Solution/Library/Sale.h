#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../include/Product.h"
#include "../include/Customer.h"

using namespace std;

class Sale {
private:
    string customerName;
    vector<pair<shared_ptr<Product>, int>> items;
    double totalAmount;
    double discount;
    double finalAmount;
    string date;

public:
    Sale(const string& customerName, const string& date);
    
    void addItem(shared_ptr<Product> product, int quantity);
    void calculateTotal(double discountRate);
    
    string getCustomerName() const;
    double getTotalAmount() const;
    double getDiscount() const;
    double getFinalAmount() const;
    string getDate() const;
    vector<pair<shared_ptr<Product>, int>> getItems() const;
};