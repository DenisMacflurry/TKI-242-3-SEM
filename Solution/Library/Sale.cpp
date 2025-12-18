#include "../include/Sale.h"

Sale::Sale(const string& customerName, const string& date)
    : customerName(customerName), totalAmount(0.0), discount(0.0), 
      finalAmount(0.0), date(date) {}

void Sale::addItem(shared_ptr<Product> product, int quantity) {
    items.push_back({product, quantity});
}

void Sale::calculateTotal(double discountRate) {
    totalAmount = 0.0;
    for (const auto& item : items) {
        totalAmount += item.first->getPrice() * item.second;
    }
    
    discount = totalAmount * discountRate;
    finalAmount = totalAmount - discount;
}

string Sale::getCustomerName() const {
    return customerName;
}

double Sale::getTotalAmount() const {
    return totalAmount;
}

double Sale::getDiscount() const {
    return discount;
}

double Sale::getFinalAmount() const {
    return finalAmount;
}

string Sale::getDate() const {
    return date;
}

vector<pair<shared_ptr<Product>, int>> Sale::getItems() const {
    return items;
}