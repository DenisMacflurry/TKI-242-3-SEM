#include <gtest/gtest.h>
#include <memory>
#include "../include/Product.h"
#include "../include/Printer.h"
#include "../include/Scanner.h"
#include "../include/Monitor.h"
#include "../include/Customer.h"
#include "../include/Sale.h"
#include "../include/Database.h"
#include "../include/Store.h"

using namespace std;

TEST(CustomerTest, BasicProperties) {
    Customer customer("Test Customer", true);
    EXPECT_EQ(customer.getName(), "Test Customer");
    EXPECT_TRUE(customer.getIsRegular());
    EXPECT_EQ(customer.getTotalPurchases(), 0.0);
}

TEST(CustomerTest, AddPurchase) {
    Customer customer("Test Customer", false);
    customer.addPurchase(5000.0);
    customer.addPurchase(3000.0);
    EXPECT_EQ(customer.getTotalPurchases(), 8000.0);
}

TEST(CustomerTest, SetRegular) {
    Customer customer("Test Customer", false);
    EXPECT_FALSE(customer.getIsRegular());
    customer.setRegular(true);
    EXPECT_TRUE(customer.getIsRegular());
}

TEST(SaleTest, AddItemsAndCalculate) {
    auto product1 = make_shared<Printer>("Printer1", "HP", 10000.0, 30);
    auto product2 = make_shared<Scanner>("Scanner1", "Canon", 5000.0, 600);
    auto customer = make_shared<Customer>("Customer1", false);
    
    Sale sale(customer, "2024-01-15");
    sale.addItem(product1, 2);
    sale.addItem(product2, 1);
    sale.calculateTotal(0.1);
    
    EXPECT_EQ(sale.getTotalAmount(), 25000.0);
    EXPECT_EQ(sale.getDiscount(), 2500.0);
    EXPECT_EQ(sale.getFinalAmount(), 22500.0);
    EXPECT_EQ(sale.getCustomer()->getName(), "Customer1");
}

TEST(DatabaseTest, AddAndFindProduct) {
    Database db;
    auto product = make_shared<Printer>("TestPrinter", "HP", 10000.0, 30);
    db.addProduct(product);
    
    auto found = db.findProductByName("TestPrinter");
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->getName(), "TestPrinter");
}

TEST(DatabaseTest, FindByManufacturer) {
    Database db;
    db.addProduct(make_shared<Printer>("Printer1", "HP", 10000.0, 30));
    db.addProduct(make_shared<Scanner>("Scanner1", "Canon", 5000.0, 600));
    db.addProduct(make_shared<Monitor>("Monitor1", "HP", 20000.0, 24.0));
    
    auto hpProducts = db.findProductsByManufacturer("HP");
    EXPECT_EQ(hpProducts.size(), 2);
}

TEST(DatabaseTest, AddAndFindCustomer) {
    Database db;
    auto customer = make_shared<Customer>("Test Customer", true);
    db.addCustomer(customer);
    
    auto found = db.findCustomerByName("Test Customer");
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->getName(), "Test Customer");
}

TEST(DatabaseTest, GetSalesByPeriod) {
    Database db;
    auto product = make_shared<Printer>("Printer1", "HP", 10000.0, 30);
    auto customer = make_shared<Customer>("Customer1", false);
    db.addProduct(product);
    db.addCustomer(customer);
    
    auto sale1 = make_shared<Sale>(customer, "2024-01-15");
    auto sale2 = make_shared<Sale>(customer, "2024-02-15");
    auto sale3 = make_shared<Sale>(customer, "2024-01-25");
    
    db.addSale(sale1);
    db.addSale(sale2);
    db.addSale(sale3);
    
    auto januarySales = db.getSalesByPeriod("2024-01-01", "2024-01-31");
    EXPECT_EQ(januarySales.size(), 2);
}

TEST(StoreTest, AddProducts) {
    Store store(10000.0, 0.1);
    store.addProduct(make_shared<Printer>("Printer1", "HP", 15000.0, 30));
    
    auto products = store.showAssortment();
    EXPECT_EQ(products.size(), 1);
}

TEST(StoreTest, AddCustomers) {
    Store store(10000.0, 0.1);
    store.addCustomer(make_shared<Customer>("Customer1", true));
    
    auto customer = store.getCustomer("Customer1");
    EXPECT_NE(customer, nullptr);
    EXPECT_EQ(customer->getName(), "Customer1");
}

TEST(StoreTest, MakePurchaseRegularCustomer) {
    Store store(10000.0, 0.1);
    store.addProduct(make_shared<Printer>("Printer1", "HP", 5000.0, 30));
    store.addCustomer(make_shared<Customer>("Customer1", true));
    
    vector<pair<string, int>> items;
    items.push_back({"Printer1", 1});
    
    auto sale = store.makePurchase("Customer1", items, "2024-01-15");
    EXPECT_NE(sale, nullptr);
    EXPECT_EQ(sale->getTotalAmount(), 5000.0);
    EXPECT_EQ(sale->getDiscount(), 500.0);
    EXPECT_EQ(sale->getFinalAmount(), 4500.0);
}

TEST(StoreTest, MakePurchaseWithThreshold) {
    Store store(10000.0, 0.1);
    store.addProduct(make_shared<Printer>("Printer1", "HP", 15000.0, 30));
    store.addCustomer(make_shared<Customer>("Customer1", false));
    
    vector<pair<string, int>> items;
    items.push_back({"Printer1", 1});
    
    auto sale = store.makePurchase("Customer1", items, "2024-01-15");
    EXPECT_NE(sale, nullptr);
    EXPECT_EQ(sale->getTotalAmount(), 15000.0);
    EXPECT_EQ(sale->getDiscount(), 1500.0);
    EXPECT_EQ(sale->getFinalAmount(), 13500.0);
}

TEST(StoreTest, MakePurchaseNoDiscount) {
    Store store(10000.0, 0.1);
    store.addProduct(make_shared<Scanner>("Scanner1", "Canon", 5000.0, 600));
    store.addCustomer(make_shared<Customer>("Customer1", false));
    
    vector<pair<string, int>> items;
    items.push_back({"Scanner1", 1});
    
    auto sale = store.makePurchase("Customer1", items, "2024-01-15");
    EXPECT_NE(sale, nullptr);
    EXPECT_EQ(sale->getTotalAmount(), 5000.0);
    EXPECT_EQ(sale->getDiscount(), 0.0);
    EXPECT_EQ(sale->getFinalAmount(), 5000.0);
}

TEST(StoreTest, GetStatisticsByProduct) {
    Store store(10000.0, 0.1);
    auto product = make_shared<Printer>("Printer1", "HP", 10000.0, 30);
    store.addProduct(product);
    store.addCustomer(make_shared<Customer>("Customer1", true));
    
    vector<pair<string, int>> items;
    items.push_back({"Printer1", 3});
    
    store.makePurchase("Customer1", items, "2024-01-15");
    
    int quantity = store.getQuantitySoldByProduct("Printer1", "2024-01-01", "2024-01-31");
    double revenue = store.getRevenueBySingleProduct("Printer1", "2024-01-01", "2024-01-31");
    
    EXPECT_EQ(quantity, 3);
    EXPECT_EQ(revenue, 30000.0);
}

TEST(StoreTest, GetTotalStatistics) {
    Store store(10000.0, 0.1);
    store.addProduct(make_shared<Printer>("Printer1", "HP", 10000.0, 30));
    store.addProduct(make_shared<Scanner>("Scanner1", "Canon", 5000.0, 600));
    store.addCustomer(make_shared<Customer>("Customer1", true));
    
    vector<pair<string, int>> items;
    items.push_back({"Printer1", 2});
    items.push_back({"Scanner1", 1});
    
    store.makePurchase("Customer1", items, "2024-01-15");
    
    int totalQuantity = store.getTotalQuantitySold("2024-01-01", "2024-01-31");
    double totalRevenue = store.getTotalRevenue("2024-01-01", "2024-01-31");
    
    EXPECT_EQ(totalQuantity, 3);
    EXPECT_EQ(totalRevenue, 22500.0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}