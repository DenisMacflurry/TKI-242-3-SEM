#include <iostream>
#include <vector>
#include <memory>
#include "../include/Product.h"
#include "../include/Printer.h"
#include "../include/Scanner.h"
#include "../include/Monitor.h"
#include "../include/Store.h"

using namespace std;

int main() {
    Store store(10000.0, 0.1);
    
    store.addProduct(make_shared<Printer>("LaserJet Pro", "HP", 15000.0, 30));
    store.addProduct(make_shared<Printer>("Pixma G3420", "Canon", 12000.0, 20));
    store.addProduct(make_shared<Scanner>("ScanSnap iX1600", "Fujitsu", 45000.0, 600));
    store.addProduct(make_shared<Scanner>("CanoScan LiDE 400", "Canon", 8000.0, 4800));
    store.addProduct(make_shared<Monitor>("UltraSharp U2723DE", "Dell", 35000.0, 27.0));
    store.addProduct(make_shared<Monitor>("ProArt PA278QV", "ASUS", 28000.0, 27.0));
    
    cout << "=== Ассортимент магазина ===" << endl;
    for (const auto& product : store.getProducts()) {
        cout << product->getInfo() << endl;
    }
    
    cout << "\n=== Поиск товаров Canon ===" << endl;
    auto canonProducts = store.findByManufacturer("Canon");
    for (const auto& product : canonProducts) {
        cout << product->getInfo() << endl;
    }
    
    cout << "\n=== Расчет покупки ===" << endl;
    vector<pair<shared_ptr<Product>, int>> purchase;
    purchase.push_back({store.getProducts()[0], 2});
    purchase.push_back({store.getProducts()[2], 1});
    
    double cost = store.calculatePurchase(purchase, false);
    cout << "Стоимость покупки со скидкой: " << cost << " руб." << endl;
    
    cout << "\n=== Статистика продаж ===" << endl;
    cout << "Всего продано товаров: " << store.getTotalQuantitySold() << " шт." << endl;
    cout << "Общая выручка: " << store.getTotalRevenue() << " руб." << endl;
    cout << "Продано LaserJet Pro: " << store.getProductQuantitySold("LaserJet Pro") << " шт." << endl;
    cout << "Выручка от LaserJet Pro: " << store.getProductRevenue("LaserJet Pro") << " руб." << endl;
    
    cout << "\n=== Итерация через коллекцию базового класса ===" << endl;
    vector<Product*> baseCollection;
    for (const auto& product : store.getProducts()) {
        baseCollection.push_back(product.get());
    }
    
    for (const auto& product : baseCollection) {
        cout << product->getInfo() << endl;
    }
    
    return 0;
}