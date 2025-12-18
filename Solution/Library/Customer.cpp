#include "../include/Customer.h"

Customer::Customer(const string& name, bool isRegular)
    : name(name), isRegular(isRegular), totalPurchases(0.0) {}

string Customer::getName() const {
    return name;
}

bool Customer::getIsRegular() const {
    return isRegular;
}

double Customer::getTotalPurchases() const {
    return totalPurchases;
}

void Customer::addPurchase(double amount) {
    totalPurchases += amount;
}

void Customer::setRegular(bool regular) {
    isRegular = regular;
}