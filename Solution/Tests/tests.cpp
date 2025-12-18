#include <gtest/gtest.h>
#include "../include/Product.h"
#include "../include/Printer.h"
#include "../include/Scanner.h"
#include "../include/Monitor.h"
#include "../include/Store.h"
#include <memory>

using namespace std;

TEST(ProductTest, BasicProperties) {
    Printer printer("TestPrinter", "TestManuf", 10000.0, 25);
    EXPECT_EQ(printer.getName(), "TestPrinter");
    EXPECT_EQ(printer.getManufacturer(), "TestManuf");
    EXPECT_EQ(printer.getPrice(), 10000.0);
    EXPECT_EQ(printer.getQuantitySold(), 0);
}

TEST(ProductTest, Sell) {
    Printer printer("TestPrinter", "TestManuf", 10000.0, 25);
    printer.sell(5);
    EXPECT_EQ(printer.getQuantitySold(), 5);
    EXPECT_EQ(printer.getTotalSales(), 50000.0);
}

TEST(StoreTest, AddProduct) {
    Store store(10000.0, 0.1);
    store.addProduct(make_shared<Printer>("Printer1", "HP", 15000.0, 30));
    EXPECT_EQ(store.getProducts().size(), 1);
}

TEST(StoreTest, FindByManufacturer) {
    Store store(10000.0, 0.1);
    store.addProduct(make_shared<Printer>("Printer1", "HP", 15000.0, 30));
    store.addProduct(make_shared<Scanner>("Scanner1", "Canon", 8000.0, 600));
    store.addProduct(make_shared<Monitor>("Monitor1", "HP", 20000.0, 24.0));
    
    auto hpProducts = store.findByManufacturer("HP");
    EXPECT_EQ(hpProducts.size(), 2);
}

TEST(StoreTest, CalculatePurchaseWithoutDiscount) {
    Store store(10000.0, 0.1);
    auto product = make_shared<Printer>("Printer1", "HP", 5000.0, 30);
    store.addProduct(product);
    
    vector<pair<shared_ptr<Product>, int>> items;
    items.push_back({product, 1});
    
    double cost = store.calculatePurchase(items, false);
    EXPECT_EQ(cost, 5000.0);
}

TEST(StoreTest, CalculatePurchaseWithDiscount) {
    Store store(10000.0, 0.1);
    auto product = make_shared<Printer>("Printer1", "HP", 15000.0, 30);
    store.addProduct(product);
    
    vector<pair<shared_ptr<Product>, int>> items;
    items.push_back({product, 1});
    
    double cost = store.calculatePurchase(items, false);
    EXPECT_EQ(cost, 13500.0);
}

TEST(StoreTest, CalculatePurchaseRegularCustomer) {
    Store store(10000.0, 0.1);
    auto product = make_shared<Scanner>("Scanner1", "Canon", 5000.0, 600);
    store.addProduct(product);
    
    vector<pair<shared_ptr<Product>, int>> items;
    items.push_back({product, 1});
    
    double cost = store.calculatePurchase(items, true);
    EXPECT_EQ(cost, 4500.0);
}

TEST(StoreTest, Statistics) {
    Store store(10000.0, 0.1);
    auto product1 = make_shared<Printer>("Printer1", "HP", 10000.0, 30);
    auto product2 = make_shared<Scanner>("Scanner1", "Canon", 5000.0, 600);
    store.addProduct(product1);
    store.addProduct(product2);
    
    vector<pair<shared_ptr<Product>, int>> items;
    items.push_back({product1, 2});
    items.push_back({product2, 1});
    
    store.calculatePurchase(items, false);
    
    EXPECT_EQ(store.getTotalQuantitySold(), 3);
    EXPECT_EQ(store.getTotalRevenue(), 25000.0);
    EXPECT_EQ(store.getProductQuantitySold("Printer1"), 2);
    EXPECT_EQ(store.getProductRevenue("Printer1"), 20000.0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}