#pragma once

#include <vector>
#include <memory>
#include <string>
#include "../include/Product.h"
#include "../include/Customer.h"
#include "../include/Sale.h"

using namespace std;

class Database {
private:
    vector<shared_ptr<Product>> products;
    vector<shared_ptr<Customer>> customers;
    vector<shared_ptr<Sale>> sales;

public:
    void addProduct(shared_ptr<Product> product);
    void addCustomer(shared_ptr<Customer> customer);
    void addSale(shared_ptr<Sale> sale);
    
    vector<shared_ptr<Product>> getProducts() const;
    vector<shared_ptr<Customer>> getCustomers() const;
    vector<shared_ptr<Sale>> getSales() const;
    
    shared_ptr<Product> findProductByName(const string& name) const;
    shared_ptr<Customer> findCustomerByName(const string& name) const;
    vector<shared_ptr<Product>> findProductsByManufacturer(const string& manufacturer) const;
    
    vector<shared_ptr<Sale>> getSalesByPeriod(const string& startDate, const string& endDate) const;
    vector<shared_ptr<Sale>> getSalesByCustomer(const string& customerName) const;
};
