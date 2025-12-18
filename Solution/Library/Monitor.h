#pragma once

#include "../include/Product.h"

using namespace std;

class Monitor : public Product {
private:
    double diagonal;

public:
    Monitor(const string& name, const string& manufacturer, double price, double diag);
    string getInfo() const override;
};
