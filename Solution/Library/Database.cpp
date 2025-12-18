#include "../include/Database.h"

void Database::addProduct(shared_ptr<Product> product) {
    products.push_back(product);
}

void Database::addCustomer(shared_ptr<Customer> customer) {
    customers.push_back(customer);
}

void Database::addSale(shared_ptr<Sale> sale) {
    sales.push_back(sale);
}

vector<shared_ptr<Product>> Database::getProducts() const {
    return products;
}

vector<shared_ptr<Customer>> Database::getCustomers() const {
    return customers;
}

vector<shared_ptr<Sale>> Database::getSales() const {
    return sales;
}

shared_ptr<Product> Database::findProductByName(const string& name) const {
    for (const auto& product : products) {
        if (product->getName() == name) {
            return product;
        }
    }
    return nullptr;
}

shared_ptr<Customer> Database::findCustomerByName(const string& name) const {
    for (const auto& customer : customers) {
        if (customer->getName() == name) {
            return customer;
        }
    }
    return nullptr;
}

vector<shared_ptr<Product>> Database::findProductsByManufacturer(const string& manufacturer) const {
    vector<shared_ptr<Product>> result;
    for (const auto& product : products) {
        if (product->getManufacturer() == manufacturer) {
            result.push_back(product);
        }
    }
    return result;
}

vector<shared_ptr<Sale>> Database::getSalesByPeriod(const string& startDate, const string& endDate) const {
    vector<shared_ptr<Sale>> result;
    for (const auto& sale : sales) {
        if (sale->getDate() >= startDate && sale->getDate() <= endDate) {
            result.push_back(sale);
        }
    }
    return result;
}

vector<shared_ptr<Sale>> Database::getSalesByCustomer(const string& customerName) const {
    vector<shared_ptr<Sale>> result;
    for (const auto& sale : sales) {
        if (sale->getCustomerName() == customerName) {
            result.push_back(sale);
        }
    }
    return result;
}