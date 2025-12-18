#pragma once

#include "Product.h"

using namespace std;

class Scanner : public Product {
private:
    int resolution;

public:
    Scanner(const string& name, const string& manufacturer, double price, int res);
    string getInfo() const override;
};
