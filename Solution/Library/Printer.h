#pragma once

#include "../include/Product.h"

using namespace std;

class Printer : public Product {
private:
    int pagesPerMinute;

public:
    Printer(const string& name, const string& manufacturer, double price, int ppm);
    string getInfo() const override;
};
