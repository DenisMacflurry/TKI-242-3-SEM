#include "../include/Store.h"

Store::Store(double threshold, double rate)
    : discountThreshold(threshold), discountRate(rate) {}

void Store::addProduct(shared_ptr<Product> product) {
    products.push_back(product);
}

vector<shared_ptr<Product>> Store::getProducts() const {
    return products;
}

vector<shared_ptr<Product>> Store::findByManufacturer(const string& manufacturer) const {
    vector<shared_ptr<Product>> result;
    for (const auto& product : products) {
        if (product->getManufacturer() == manufacturer) {
            result.push_back(product);
        }
    }
    return result;
}

double Store::calculatePurchase(const vector<pair<shared_ptr<Product>, int>>& items, bool isRegularCustomer) const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.first->getPrice() * item.second;
        item.first->sell(item.second);
    }
    
    if (isRegularCustomer || total >= discountThreshold) {
        total *= (1.0 - discountRate);
    }
    
    return total;
}

int Store::getTotalQuantitySold() const {
    int total = 0;
    for (const auto& product : products) {
        total += product->getQuantitySold();
    }
    return total;
}

double Store::getTotalRevenue() const {
    double total = 0.0;
    for (const auto& product : products) {
        total += product->getTotalSales();
    }
    return total;
}

int Store::getProductQuantitySold(const string& productName) const {
    for (const auto& product : products) {
        if (product->getName() == productName) {
            return product->getQuantitySold();
        }
    }
    return 0;
}

double Store::getProductRevenue(const string& productName) const {
    for (const auto& product : products) {
        if (product->getName() == productName) {
            return product->getTotalSales();
        }
    }
    return 0.0;
}