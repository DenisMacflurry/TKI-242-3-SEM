#include <iostream>
#include <vector>
#include <memory>
#include "../include/Product.h"
#include "../include/Printer.h"
#include "../include/Scanner.h"
#include "../include/Monitor.h"
#include "../include/Customer.h"
#include "../include/Sale.h"
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
    
    store.addCustomer(make_shared<Customer>("Иванов Иван", true));
    store.addCustomer(make_shared<Customer>("Петров Петр", false));
    store.addCustomer(make_shared<Customer>("Сидорова Анна", false));
    
    cout << "=== Ассортимент магазина ===" << endl;
    auto products = store.showAssortment();
    for (const auto& product : products) {
        cout << product->getInfo() << endl;
    }
    
    cout << "\n=== Поиск товаров Canon ===" << endl;
    auto canonProducts = store.findByManufacturer("Canon");
    for (const auto& product : canonProducts) {
        cout << product->getInfo() << endl;
    }
    
    cout << "\n=== Покупка 1: постоянный клиент Иванов ===" << endl;
    vector<pair<string, int>> purchase1;
    purchase1.push_back({"LaserJet Pro", 1});
    purchase1.push_back({"CanoScan LiDE 400", 1});
    
    auto sale1 = store.makePurchase("Иванов Иван", purchase1, "2024-01-15");
    if (sale1) {
        cout << "Клиент: " << sale1->getCustomer()->getName() << endl;
        cout << "Сумма до скидки: " << sale1->getTotalAmount() << " руб." << endl;
        cout << "Скидка: " << sale1->getDiscount() << " руб." << endl;
        cout << "Итого к оплате: " << sale1->getFinalAmount() << " руб." << endl;
    }
    
    cout << "\n=== Покупка 2: обычный клиент Петров (малая сумма) ===" << endl;
    vector<pair<string, int>> purchase2;
    purchase2.push_back({"CanoScan LiDE 400", 1});
    
    auto sale2 = store.makePurchase("Петров Петр", purchase2, "2024-01-20");
    if (sale2) {
        cout << "Клиент: " << sale2->getCustomer()->getName() << endl;
        cout << "Сумма до скидки: " << sale2->getTotalAmount() << " руб." << endl;
        cout << "Скидка: " << sale2->getDiscount() << " руб." << endl;
        cout << "Итого к оплате: " << sale2->getFinalAmount() << " руб." << endl;
    }
    
    cout << "\n=== Покупка 3: обычный клиент Сидорова (большая сумма) ===" << endl;
    vector<pair<string, int>> purchase3;
    purchase3.push_back({"ScanSnap iX1600", 1});
    purchase3.push_back({"UltraSharp U2723DE", 1});
    
    auto sale3 = store.makePurchase("Сидорова Анна", purchase3, "2024-01-25");
    if (sale3) {
        cout << "Клиент: " << sale3->getCustomer()->getName() << endl;
        cout << "Сумма до скидки: " << sale3->getTotalAmount() << " руб." << endl;
        cout << "Скидка: " << sale3->getDiscount() << " руб." << endl;
        cout << "Итого к оплате: " << sale3->getFinalAmount() << " руб." << endl;
    }
    
    cout << "\n=== Статистика продаж за период 2024-01-01 - 2024-01-31 ===" << endl;
    cout << "Всего продано товаров: " << store.getTotalQuantitySold("2024-01-01", "2024-01-31") << " шт." << endl;
    cout << "Общая выручка: " << store.getTotalRevenue("2024-01-01", "2024-01-31") << " руб." << endl;
    
    cout << "\n=== Статистика по товару CanoScan LiDE 400 ===" << endl;
    cout << "Продано: " << store.getQuantitySoldByProduct("CanoScan LiDE 400", "2024-01-01", "2024-01-31") << " шт." << endl;
    cout << "Выручка: " << store.getRevenueBySingleProduct("CanoScan LiDE 400", "2024-01-01", "2024-01-31") << " руб." << endl;
    
    cout << "\n=== Информация о клиентах ===" << endl;
    auto customer1 = store.getCustomer("Иванов Иван");
    if (customer1) {
        cout << "Клиент: " << customer1->getName() 
             << ", постоянный: " << (customer1->getIsRegular() ? "да" : "нет")
             << ", всего покупок на сумму: " << customer1->getTotalPurchases() << " руб." << endl;
    }
    
    auto customer2 = store.getCustomer("Петров Петр");
    if (customer2) {
        cout << "Клиент: " << customer2->getName() 
             << ", постоянный: " << (customer2->getIsRegular() ? "да" : "нет")
             << ", всего покупок на сумму: " << customer2->getTotalPurchases() << " руб." << endl;
    }
    
    auto customer3 = store.getCustomer("Сидорова Анна");
    if (customer3) {
        cout << "Клиент: " << customer3->getName() 
             << ", постоянный: " << (customer3->getIsRegular() ? "да" : "нет")
             << ", всего покупок на сумму: " << customer3->getTotalPurchases() << " руб." << endl;
    }
    
    cout << "\n=== Итерация через коллекцию базового класса ===" << endl;
    vector<Product*> baseCollection;
    for (const auto& product : store.showAssortment()) {
        baseCollection.push_back(product.get());
    }
    
    for (const auto& product : baseCollection) {
        cout << product->getInfo() << endl;
    }
    
    return 0;
}