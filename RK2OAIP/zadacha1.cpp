#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>
#include <list>

using namespace std;

class ServiceRecord {
public:
    string date;
    string description;
    ServiceRecord(string d, string desc) : date(d), description(desc) {}
    string toString() const {
        return date + ": " + description;
    }
};

class MusicalInstrument {
protected:
    string name;
    string brand;
    string model;
    vector<ServiceRecord> serviceRecords;

public:
    MusicalInstrument(string n, string b, string m) : name(n), brand(b), model(m) {}
    
    virtual ~MusicalInstrument() {}
    
    virtual void display() const {
        cout << name << " | " << brand << " | " << model;
        if (!serviceRecords.empty()) {
            cout << " [Обслуживание: ";
            for (const auto& rec : serviceRecords) {
                cout << rec.toString() << " | ";
            }
            cout << "]";
        }
    }
    
    void addServiceRecord(const ServiceRecord& rec) {
        serviceRecords.push_back(rec);
    }
    
    bool hasServiceRecord(const string& keyword) const {
        for (const auto& rec : serviceRecords) {
            if (rec.description.find(keyword) != string::npos) {
                return true;
            }
        }
        return false;
    }
    
    string getBrand() const { return brand; }
    string getName() const { return name; }
    string getModel() const { return model; }
};

class StringInstrument : public MusicalInstrument {
private:
    int stringCount;
    string bodyMaterial;

public:
    StringInstrument(string n, string b, string m, int sc, string bm)
        : MusicalInstrument(n, b, m), stringCount(sc), bodyMaterial(bm) {}
    
    void display() const override {
        MusicalInstrument::display();
        cout << " Струн: " << stringCount << " Материал: " << bodyMaterial;
    }
    
    int getStringCount() const { return stringCount; }
};

class BrassInstrument : public MusicalInstrument {
private:
    string valveType;
    string material;

public:
    BrassInstrument(string n, string b, string m, string vt, string mat)
        : MusicalInstrument(n, b, m), valveType(vt), material(mat) {}
    
    void display() const override {
        MusicalInstrument::display();
        cout << " Клапаны: " << valveType << " Материал: " << material;
    }
    
    string getValveType() const { return valveType; }
};

class InstrumentManager {
private:
    list<unique_ptr<MusicalInstrument>> instruments;

public:
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) return;
        
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string type, name, brand, model, extra1, extra2;
            getline(ss, type, ';');
            getline(ss, name, ';');
            getline(ss, brand, ';');
            getline(ss, model, ';');
            getline(ss, extra1, ';');
            getline(ss, extra2, ';');
            if (type == "String") {
                instruments.push_back(make_unique<StringInstrument>(
                    name, brand, model, stoi(extra1), extra2));
            } else if (type == "Brass") {
                instruments.push_back(make_unique<BrassInstrument>(
                    name, brand, model, extra1, extra2));
            }
            
            string services;
            getline(ss, services, ';');
            stringstream sss(services);
            string serviceItem;
            while (getline(sss, serviceItem, '|')) {
                stringstream ssss(serviceItem);
                string date, desc;
                getline(ssss, date, ',');
                getline(ssss, desc, ',');
                instruments.back()->addServiceRecord(ServiceRecord(date, desc));
            }
        }
    }
    
    void displayAll() const {
        for (const auto& instr : instruments) {
            instr->display();
            cout << endl;
        }
    }
    
    void filterByStringCount(int count) {
        for (const auto& instr : instruments) {
            auto si = dynamic_cast<StringInstrument*>(instr.get());
            if (si && si->getStringCount() == count) {
                instr->display();
                cout << endl;
            }
        }
    }
    
    void filterByService(const string& keyword) {
        for (const auto& instr : instruments) {
            if (instr->hasServiceRecord(keyword)) {
                instr->display();
                cout << endl;
            }
        }
    }
    void sortByBrand() {
        instruments.sort([](const unique_ptr<MusicalInstrument>& a, 
                           const unique_ptr<MusicalInstrument>& b) {
            return a->getBrand() < b->getBrand();
        });
    }
    
    void addInstrument(unique_ptr<MusicalInstrument> instr) {
        instruments.push_back(move(instr));
    }
    
    void removeInstrument(const string& name) {
        instruments.remove_if([&name](const unique_ptr<MusicalInstrument>& instr) {
            return instr->getName() == name;
        });
    }
    void saveToFile(const string& filename) {
        ofstream file(filename);
        for (const auto& instr : instruments) {
            file << instr->getName() << ";" << instr->getBrand() << ";" << instr->getModel() << endl;
        }
    }
    bool isEmpty() const {
        return instruments.empty();
    }
};

int main() {
    InstrumentManager manager;
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Загрузить из файла\n"; //название файла в тхт. это важно!!!!!!!!!!!!!!!!!!!!!!!!!
        cout << "2. Показать все инструменты\n";
        cout << "3. Фильтр по количеству струн\n";
        cout << "4. Фильтр по обслуживанию\n";
        cout << "5. Сортировать по бренду\n";
        cout << "6. Добавить инструмент\n";
        cout << "7. Удалить инструмент\n";
        cout << "8. Сохранить в файл\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1: {
                cout << "Имя файла c .txt: ";
                string filename;
                getline(cin, filename);
                manager.loadFromFile(filename);
                cout << "Данные загружены\n";
                break;
            }
            case 2:
                if (manager.isEmpty()) {
                    cout << "Нет инструментов\n";
                } else {
                    cout << "\nСписок инструментов:\n";
                    manager.displayAll();
                }
                break;
            case 3: {
                if (manager.isEmpty()) {
                    cout << "Нет инструментов\n";
                    break;
                }
                cout << "Количество струн: ";
                int count;
                cin >> count;
                cout << "\nРезультаты поиска:\n";
                manager.filterByStringCount(count);
                break;
            }
            case 4: {
                if (manager.isEmpty()) {
                    cout << "Нет инструментов\n";
                    break;
                }
                cout << "Ключевое слово для обслуживания: ";
                string keyword;
                getline(cin, keyword);
                cout << "\nРезультаты поиска:\n";
                manager.filterByService(keyword);
                break;
            }
            case 5:
                if (manager.isEmpty()) {
                    cout << "Нет инструментов\n";
                } else {
                    manager.sortByBrand();
                    cout << "\nОтсортировано по бренду:\n";
                    manager.displayAll();
                }
                break;
            case 6: {
                cout << "Тип (1-Струнный, 2-Медный): ";
                int type;
                cin >> type;
                cin.ignore();
                string name, brand, model, extra1, extra2;
                cout << "Название: "; getline(cin, name);
                cout << "Бренд: "; getline(cin, brand);
                cout << "Модель: "; getline(cin, model);
                if (type == 1) {
                    cout << "Количество струн: "; getline(cin, extra1);
                    cout << "Материал корпуса: "; getline(cin, extra2);
                    manager.addInstrument(make_unique<StringInstrument>(
                        name, brand, model, stoi(extra1), extra2));
                } else {
                    cout << "Тип клапанов: "; getline(cin, extra1);
                    cout << "Материал: "; getline(cin, extra2);
                    manager.addInstrument(make_unique<BrassInstrument>(
                        name, brand, model, extra1, extra2));
                }
                cout << "Инструмент добавлен\n";
                break;
            }
            case 7: {
                if (manager.isEmpty()) {
                    cout << "Нет инструментов\n";
                    break;
                }
                cout << "Название инструмента для удаления: ";
                string name;
                getline(cin, name);
                manager.removeInstrument(name);
                cout << "Инструмент удален\n";
                break;
            }
            case 8: {
                cout << "Имя файла: ";
                string filename;
                getline(cin, filename);
                manager.saveToFile(filename);
                cout << "Данные сохранены\n";
                break;
            }
            case 0:
                cout << "Выход\n";
                break;
            default:
                cout << "Неверный выбор\n";
        }
    } while(choice != 0);
    return 0;
}