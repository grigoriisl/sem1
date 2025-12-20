#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <pqxx/pqxx>
using namespace std;

template<typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(const T1& f, const T2& s) : first(f), second(s) {}
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
};

class DatabaseHandler {
protected:
    shared_ptr<pqxx::connection> conn;
    ofstream logFile;
public:
    DatabaseHandler() {
        try {
            conn = make_shared<pqxx::connection>(
                "dbname=products_db user=postgres password=10012007 host=localhost port=5432"
            );
            if (conn->is_open()) {
                cout << "connected!" << endl;
                logFile.open("log.txt", ios::app);
                log("database connection");
            } else {
                cerr << "failed to connect to database!" << endl;
            }
        } catch (const exception &e) {
            cerr << "connection error: " << e.what() << endl;
        }
    }
    
    void log(const string& message) {
        if (logFile.is_open()) {
            logFile << message << endl;
        }
    }
    shared_ptr<pqxx::connection> getConnection() const {
        return conn;
    }
};

class Category : public DatabaseHandler {
public:
    void addCategory(const string& category_name) {
        try {
            pqxx::work txn(*conn);
            string query = "INSERT INTO categories (category_name) VALUES (" 
                          + txn.quote(category_name) + ")";
            txn.exec(query);
            txn.commit();
            log("added category: " + category_name);
            cout << "category added successfully!" << endl;
        } catch (const exception& e) {
            cerr << "error adding category: " << e.what() << endl;
        }
    }
    
    void getAllCategories() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec("SELECT * FROM categories ORDER BY id");
            cout << "\n=== categories ===" << endl;
            for (const auto& row : res) {
                cout << "id: " << row["id"].as<int>()
                      << ", name: " << row["category_name"].c_str() << endl;
            }
            log("viewed all categories");
        } catch (const exception& e) {
            cerr << "error: " << e.what() << endl;
        }
    }
};

class Product : public DatabaseHandler {
protected:
    string name;
    double price;
    int quantity;
    int category_id;
    
public:
    virtual void addProduct(const string& name, double price, int quantity, int category_id) {
        try {
            pqxx::work txn(*conn);
            string query = "INSERT INTO products (name, price, quantity, category_id) VALUES ("
                          + txn.quote(name) + ", "
                          + txn.quote(price) + ", "
                          + txn.quote(quantity) + ", "
                          + txn.quote(category_id) + ")";
            txn.exec(query);
            txn.commit();
            log("added product: " + name);
            cout << "product added successfully!" << endl;
        } catch (const exception& e) {
            cerr << "error adding product: " << e.what() << endl;
        }
    }
    
    void getAllProducts() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(
                "SELECT p.id, p.name, p.price, p.quantity, c.category_name "
                "FROM products p "
                "JOIN categories c ON p.category_id = c.id "
                "ORDER BY p.id"
            );
            cout << "\n=== products ===" << endl;
            for (const auto& row : res) {
                cout << "id: " << row["id"].as<int>()
                      << ", name: " << row["name"].c_str()
                      << ", price: $" << row["price"].as<double>()
                      << ", quantity: " << row["quantity"].as<int>()
                      << ", category: " << row["category_name"].c_str() << endl;
            }
            log("viewed all products");
        } catch (const exception& e) {
            cerr << "error: " << e.what() << endl;
        }
    }
    
    void getProductsByCategory(int category_id) {
        try {
            pqxx::work txn(*conn);
            string query = 
                "SELECT p.id, p.name, p.price, p.quantity "
                "FROM products p "
                "WHERE p.category_id = " + txn.quote(category_id) + " "
                "ORDER BY p.name";
            pqxx::result res = txn.exec(query);
            cout << "\n=== products in category id " << category_id << " ===" << endl;
            for (const auto& row : res) {
                cout << "id: " << row["id"].as<int>()
                      << ", name: " << row["name"].c_str()
                      << ", price: $" << row["price"].as<double>()
                      << ", quantity: " << row["quantity"].as<int>() << endl;
            }
            log("viewed products by category id: " + to_string(category_id));
        } catch (const exception& e) {
            cerr << "error: " << e.what() << endl;
        }
    }
};

class PhysicalProduct : public Product {
public:
    void addProduct(const string& name, double price, int quantity, int category_id) override {
        Product::addProduct(name, price, quantity, category_id);
        log("added physical product: " + name);
    }
};

class DigitalProduct : public Product {
public:
    void addProduct(const string& name, double price, int quantity, int category_id) override {
        Product::addProduct(name, price, quantity, category_id);
        log("added digital product: " + name);
    }
};

class Sale : public DatabaseHandler {
public:
    void addSale(int product_id, int quantity_sold) {
        try {
            pqxx::work txn(*conn);
            
            string query = 
                "INSERT INTO sales (product_id, quantity_sold) VALUES ("
                + txn.quote(product_id) + ", "
                + txn.quote(quantity_sold) + ")";
            txn.exec(query);
            
            txn.exec("UPDATE products SET quantity = quantity - " 
                    + txn.quote(quantity_sold) 
                    + " WHERE id = " + txn.quote(product_id));
            
            txn.commit();
            log("added sale for product id: " + to_string(product_id) 
                + ", quantity: " + to_string(quantity_sold));
            cout << "sale recorded successfully!" << endl;
        } catch (const exception& e) {
            cerr << "error recording sale: " << e.what() << endl;
        }
    }
    
    void getAllSales() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(
                "SELECT s.id, p.name, s.sale_date, s.quantity_sold, p.price, "
                "(s.quantity_sold * p.price) as total_amount "
                "FROM sales s "
                "JOIN products p ON s.product_id = p.id "
                "ORDER BY s.sale_date DESC, s.id"
            );
            
            cout << "\n=== sales history ===" << endl;
            for (const auto& row : res) {
                cout << "id: " << row["id"].as<int>()
                      << ", product: " << row["name"].c_str()
                      << ", date: " << row["sale_date"].as<string>()
                      << ", quantity: " << row["quantity_sold"].as<int>()
                      << ", total:s " << row["total_amount"].as<double>() << endl;
            }
            log("viewed all sales");
        } catch (const exception& e) {
            cerr << "error: " << e.what() << endl;
        }
    }
    
    void getTotalRevenue() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(
                "SELECT SUM(s.quantity_sold * p.price) as total_revenue "
                "FROM sales s "
                "JOIN products p ON s.product_id = p.id"
            );
            if (!res.empty()) {
                double revenue = res[0]["total_revenue"].as<double>();
                cout << "\n=== total revenue ===" << endl;
                cout << "total revenue: $" << revenue << endl;
                log("viewed total revenue: $" + to_string(revenue));
            }
        } catch (const exception& e) {
            cerr << "error: " << e.what() << endl;
        }
    }
    
    void getProductsSoldQuantity() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(
                "SELECT p.name, SUM(s.quantity_sold) as total_sold "
                "FROM products p "
                "JOIN sales s ON p.id = s.product_id "
                "GROUP BY p.name "
                "ORDER BY total_sold DESC"
            );
            cout << "\n=== products sold quantity ===" << endl;
            for (const auto& row : res) {
                cout << "product: " << row["name"].c_str()
                      << ", total sold: " << row["total_sold"].as<int>() << endl;
            }
            log("viewed products sold quantity");
        } catch (const exception& e) {
            cerr << "error: " << e.what() << endl;
        }
    }
    
    void getTopSellingProducts() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(
                "SELECT p.name, SUM(s.quantity_sold) as total_sold "
                "FROM products p "
                "JOIN sales s ON p.id = s.product_id "
                "GROUP BY p.name "
                "ORDER BY total_sold DESC "
                "LIMIT 5"
            );
            cout << "\n=== top 5 selling products ===" << endl;
            int rank = 1;
            for (const auto& row : res) {
                cout << rank++ << ". " << row["name"].c_str()
                      << " - sold: " << row["total_sold"].as<int>() << " units" << endl;
            }
            log("viewed top 5 selling products");
        } catch (const exception& e) {
            cerr << "error: " << e.what() << endl;
        }
    }
};

void displayMenu() {
    cout << "\n=== product management system ===" << endl;
    cout << "1. add category" << endl;
    cout << "2. add product" << endl;
    cout << "3. add sale" << endl;
    cout << "4. view all categories" << endl;
    cout << "5. view all products" << endl;
    cout << "6. view all sales" << endl;
    cout << "7. view products by category" << endl;
    cout << "8. view total revenue" << endl;
    cout << "9. view products sold quantity" << endl;
    cout << "10. view top 5 selling products" << endl;
    cout << "0. exit" << endl;
    cout << "enter your choice: ";
}

int main() {
    Category categoryManager;
    Product productManager;
    Sale saleManager;
    PhysicalProduct physicalProduct;
    DigitalProduct digitalProduct;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                string categoryName;
                cout << "enter category name: ";
                cin.ignore();
                getline(cin, categoryName);
                categoryManager.addCategory(categoryName);
                break;
            }
            case 2: {
                string productName;
                double price;
                int quantity, categoryId, productType;
                cout << "enter product name: ";
                cin.ignore();
                getline(cin, productName);
                cout << "enter price: ";
                cin >> price;
                cout << "enter quantity: ";
                cin >> quantity;
                cout << "enter category id: ";
                cin >> categoryId;
                cout << "product type (1 - physical, 2 - digital): ";
                cin >> productType;
                if (productType == 1) {
                    physicalProduct.addProduct(productName, price, quantity, categoryId);
                } else if (productType == 2) {
                    digitalProduct.addProduct(productName, price, quantity, categoryId);
                } else {
                    productManager.addProduct(productName, price, quantity, categoryId);
                }
                break;
            }
            case 3: {
                int productId, quantity;
                cout << "enter product id: ";
                cin >> productId;
                cout << "enter quantity sold: ";
                cin >> quantity;
                saleManager.addSale(productId, quantity);
                break;
            }
            case 4:
                categoryManager.getAllCategories();
                break;
            case 5:
                productManager.getAllProducts();
                break;
            case 6:
                saleManager.getAllSales();
                break;
            case 7: {
                int categoryId;
                cout << "enter category id: ";
                cin >> categoryId;
                productManager.getProductsByCategory(categoryId);
                break;
            }
            case 8:
                saleManager.getTotalRevenue();
                break;
            case 9:
                saleManager.getProductsSoldQuantity();
                break;
            case 10:
                saleManager.getTopSellingProducts();
                break;
            case 0:
                cout << "exiting program..." << endl;
                break;
            default:
                cout << "invalid choice! please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}