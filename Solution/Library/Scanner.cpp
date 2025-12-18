#include "../include/Scanner.h"

Scanner::Scanner(const string& name, const string& manufacturer, double price, int res)
    : Product(name, manufacturer, price), resolution(res) {}

string Scanner::getInfo() const {
    return "Сканер: " + name + ", производитель: " + manufacturer + 
           ", цена: " + to_string(price) + " руб., разрешение: " + 
           to_string(resolution) + " dpi";
}