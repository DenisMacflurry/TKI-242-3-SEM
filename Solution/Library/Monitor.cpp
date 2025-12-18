#include "../include/Monitor.h"

Monitor::Monitor(const string& name, const string& manufacturer, double price, double diag)
    : Product(name, manufacturer, price), diagonal(diag) {}

string Monitor::getInfo() const {
    return "Монитор: " + name + ", производитель: " + manufacturer + 
           ", цена: " + to_string(price) + " руб., диагональ: " + 
           to_string(diagonal) + "\"";
}