#pragma once

#include <string>

using namespace std;

class Customer {
private:
    string name;
    bool isRegular;
    double totalPurchases;

public:
    Customer(const string& name, bool isRegular = false);
    
    string getName() const;
    bool getIsRegular() const;
    double getTotalPurchases() const;
    
    void addPurchase(double amount);
    void setRegular(bool regular);
};