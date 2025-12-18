#include "../include/Product.h"

Product::Product(const string& name, const string& manufacturer, double price)
    : name(name), manufacturer(manufacturer), price(price), quantitySold(0) {}

Product::~Product() {}

string Product::getName() const {
    return name;
}

string Product::getManufacturer() const {
    return manufacturer;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantitySold() const {
    return quantitySold;
}

void Product::sell(int quantity) {
    quantitySold += quantity;
}

double Product::getTotalSales() const {
    return price * quantitySold;
}