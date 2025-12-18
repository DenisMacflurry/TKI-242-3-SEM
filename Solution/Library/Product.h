#pragma once

#include <string>

using namespace std;

class Product {
protected:
    string name;
    string manufacturer;
    double price;
    int quantitySold;

public:
    Product(const string& name, const string& manufacturer, double price);
    virtual ~Product();
    
    string getName() const;
    string getManufacturer() const;
    double getPrice() const;
    int getQuantitySold() const;
    
    void sell(int quantity);
    double getTotalSales() const;
    
    virtual string getInfo() const = 0;
};