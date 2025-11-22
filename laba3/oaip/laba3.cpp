#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> readFile() {
    vector<string> lines;
    ifstream file("products.txt");
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}

void writeFile(const vector<string>& lines) {
    ofstream file("products.txt");
    for (const string& line : lines) {
        file << line << endl;
    }
    file.close();
}

void createFile() {
    ofstream file("products.txt");
    cout << "Ввод продуктов (название, цена, количество)\n";
    cout << "Пустая строка в названии - конец ввода\n";
    while (true) {
        string name, price, quantity;
        cout << "Название: ";
        getline(cin, name);
        if (name.empty()) break;
        cout << "Цена: ";
        getline(cin, price);
        cout << "Количество: ";
        getline(cin, quantity);
        file << name << "," << price << "," << quantity << endl;
    }
    file.close();
    cout << "Файл создан\n";
}

void searchProduct() {
    string searchName;
    cout << "Название для поиска: ";
    getline(cin, searchName);
    vector<string> products = readFile();
    bool found = false;
    for (const string& line : products) {
        size_t pos = line.find(',');
        string name = line.substr(0, pos);   
        if (name == searchName) {
            cout << "Найден: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Не найден\n";
    }
}

void sortByPrice() {
    vector<string> products = readFile();
    sort(products.begin(), products.end(), [](const string& a, const string& b) {
        double priceA = stod(a.substr(a.find(',') + 1, a.rfind(',') - a.find(',') - 1));
        double priceB = stod(b.substr(b.find(',') + 1, b.rfind(',') - b.find(',') - 1));
        return priceA < priceB;
    });
    writeFile(products);
    cout << "Отсортировано по цене\n";
}

void sortByQuantity() {
    vector<string> products = readFile();
    sort(products.begin(), products.end(), [](const string& a, const string& b) {
        int qtyA = stoi(a.substr(a.rfind(',') + 1));
        int qtyB = stoi(b.substr(b.rfind(',') + 1));
        return qtyA < qtyB;
    });
    writeFile(products);
    cout << "Отсортировано по количеству\n";
}

void addProduct() {
    string name, price, quantity;
    cout << "Новый продукт:\n";
    cout << "Название: ";
    getline(cin, name);
    cout << "Цена: ";
    getline(cin, price);
    cout << "Количество: ";
    getline(cin, quantity);
    ofstream file("products.txt", ios::app);
    file << name << "," << price << "," << quantity << endl;
    file.close();
    cout << "Продукт добавлен\n";
}

void showByMaxPrice() {
    double maxPrice;
    cout << "Максимальная цена: ";
    cin >> maxPrice;
    cin.ignore();
    vector<string> products = readFile();
    bool found = false;
    for (const string& line : products) 
    {
        size_t firstComma = line.find(',');
        size_t lastComma = line.rfind(',');
        double price = stod(line.substr(firstComma + 1, lastComma - firstComma - 1));
        if (price <= maxPrice) {
            cout << line << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Нет продуктов\n";
    }
}

void showAll() {
    vector<string> products = readFile();
    if (products.empty()) {
        cout << "Файл пуст\n";
        return;
    }
    cout << "Все продукты:\n";
    for (const string& line : products) {
        cout << line << endl;
    }
}

int main() 
{
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Создать файл\n";
        cout << "2. Поиск\n";
        cout << "3. Сортировка по цене\n";
        cout << "4. Сортировка по количеству\n";
        cout << "5. Добавить продукт\n";
        cout << "6. Продукты по цене\n";
        cout << "7. Показать все\n";
        cout << "8. Выход\n";
        cout << "Выбор: ";
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1: createFile(); break;
            case 2: searchProduct(); break;
            case 3: sortByPrice(); break;
            case 4: sortByQuantity(); break;
            case 5: addProduct(); break;
            case 6: showByMaxPrice(); break;
            case 7: showAll(); break;
            case 8: cout << "Выход\n"; break;
            default: cout << "Неверный выбор\n";
        }
    } while (choice != 8);
    return 0;
}