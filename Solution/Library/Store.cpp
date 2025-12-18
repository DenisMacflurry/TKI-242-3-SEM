#include "../include/Store.h"

Store::Store(double threshold, double rate)
    : discountThreshold(threshold), discountRate(rate) {}

void Store::addProduct(shared_ptr<Product> product) {
    database.addProduct(product);
}

void Store::addCustomer(shared_ptr<Customer> customer) {
    database.addCustomer(customer);
}

vector<shared_ptr<Product>> Store::showAssortment() const {
    return database.getProducts();
}

vector<shared_ptr<Product>> Store::findByManufacturer(const string& manufacturer) const {
    return database.findProductsByManufacturer(manufacturer);
}

shared_ptr<Sale> Store::makePurchase(const string& customerName,
                                      const vector<pair<string, int>>& items,
                                      const string& date) {
    auto customer = database.findCustomerByName(customerName);
    if (!customer) {
        return nullptr;
    }
    
    auto sale = make_shared<Sale>(customerName, date);
    
    for (const auto& item : items) {
        auto product = database.findProductByName(item.first);
        if (product) {
            sale->addItem(product, item.second);
            product->sell(item.second);
        }
    }
    
    double discountToApply = 0.0;
    
    double saleTotal = 0.0;
    for (const auto& item : sale->getItems()) {
        saleTotal += item.first->getPrice() * item.second;
    }
    
    if (customer->getIsRegular() || saleTotal >= discountThreshold) {
        discountToApply = discountRate;
    }
    
    sale->calculateTotal(discountToApply);
    
    customer->addPurchase(sale->getFinalAmount());
    database.addSale(sale);
    
    return sale;
}

int Store::getQuantitySoldByProduct(const string& productName,
                                    const string& startDate,
                                    const string& endDate) const {
    int total = 0;
    auto sales = database.getSalesByPeriod(startDate, endDate);
    
    for (const auto& sale : sales) {
        for (const auto& item : sale->getItems()) {
            if (item.first->getName() == productName) {
                total += item.second;
            }
        }
    }
    
    return total;
}

double Store::getRevenueBySingleProduct(const string& productName,
                                        const string& startDate,
                                        const string& endDate) const {
    double total = 0.0;
    auto sales = database.getSalesByPeriod(startDate, endDate);
    
    for (const auto& sale : sales) {
        for (const auto& item : sale->getItems()) {
            if (item.first->getName() == productName) {
                total += item.first->getPrice() * item.second;
            }
        }
    }
    
    return total;
}

int Store::getTotalQuantitySold(const string& startDate, const string& endDate) const {
    int total = 0;
    auto sales = database.getSalesByPeriod(startDate, endDate);
    
    for (const auto& sale : sales) {
        for (const auto& item : sale->getItems()) {
            total += item.second;
        }
    }
    
    return total;
}

double Store::getTotalRevenue(const string& startDate, const string& endDate) const {
    double total = 0.0;
    auto sales = database.getSalesByPeriod(startDate, endDate);
    
    for (const auto& sale : sales) {
        total += sale->getFinalAmount();
    }
    
    return total;
}

shared_ptr<Customer> Store::getCustomer(const string& name) const {
    return database.findCustomerByName(name);
}