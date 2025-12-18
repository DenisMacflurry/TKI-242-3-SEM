#include "../include/Printer.h"

Printer::Printer(const string& name, const string& manufacturer, double price, int ppm)
    : Product(name, manufacturer, price), pagesPerMinute(ppm) {}

string Printer::getInfo() const {
    return "Принтер: " + name + ", производитель: " + manufacturer + 
           ", цена: " + to_string(price) + " руб., скорость: " + 
           to_string(pagesPerMinute) + " стр/мин";
}