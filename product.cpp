#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Product {
    int id;
    char* name;
    char* description;
    double price;
    double* priceHistory;

public:
    Product(int id, const char* name, const char* description, double price, const double* priceHistory) {
        this->id = id;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->description = new char[strlen(description) + 1];
        strcpy(this->description, description);
        this->price = price;

        int historySize = 0;
        while (priceHistory[historySize] != -1) {
            historySize++;
        }

        this->priceHistory = new double[historySize + 1];
        for (int i = 0; i < historySize; i++) {
            this->priceHistory[i] = priceHistory[i];
        }
        this->priceHistory[historySize] = -1;
    }

    Product(const Product& p) {
        this->id = p.id;
        this->name = new char[strlen(p.name) + 1];
        strcpy(this->name, p.name);
        this->description = new char[strlen(p.description) + 1];
        strcpy(this->description, p.description);
        this->price = p.price;
        double previousprice = p.price;
        int historySize = 0;
        while (p.priceHistory[historySize] != -1) {
            historySize++;
        }

        this->priceHistory = new double[historySize + 1];
        for (int i = 0; i < historySize; i++) {
            this->priceHistory[i] = p.priceHistory[i];
        }
        this->priceHistory[historySize] = -1;
    }

    void setPrice(double newPrice) {
        double previousprice = price;
        int historySize = 0;
        while (priceHistory[historySize] != -1) {
            historySize++;
        }

        double* newPriceHistory = new double[historySize + 2];
        for (int i = 0; i < historySize; i++) {
            newPriceHistory[i] = priceHistory[i];
        }
        newPriceHistory[historySize] = newPrice;
       
        newPriceHistory[historySize + 1] = -1;

      
        price = newPrice;
        delete[] priceHistory;
        priceHistory = newPriceHistory;
    }

    int getId() const {
        return id;
    }

    double getPrice() const {
        return price;
    }

    void setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    const char* getName() const {
        return name;
    }

    void setDescription(const char* newDescription) {
        delete[] description;
        description = new char[strlen(newDescription) + 1];
        strcpy(description, newDescription);
    }

    const char* getDescription() const {
        return description;
    }

    double getPriceAverage(double previousprice) {
        int historySize = 0;
        while (priceHistory[historySize] != -1) {
            historySize++;
        }
        double sum = 0;
        for (int i = 0; i < historySize; i++) {
            sum += priceHistory[i];
        }
        sum = sum + previousprice;
        historySize++;
        return sum / historySize;
    }

    ~Product() {
        delete[] name;
        delete[] description;
        delete[] priceHistory;
    }
};

int main() {
    int id;
    char name[100];
    char description[100];
    double price;
    int historySize;

    cout << "Introduceti ID: ";
    cin >> id;
    cin.ignore();
    cout << "Introduceti nume: ";
    cin.getline(name, 100);
    cout << "Introduceti descriere: ";
    cin.getline(description, 100);
    cout << "Introduceti pret: ";
    cin >> price;
    cout << "Introduceti dimensiunea istoricului preturilor: ";
    cin >> historySize;
    double previousprice = price;
    double* priceHistory = new double[historySize + 2];
    for (int i = 0; i < historySize; i++) {
        cout << "Introduceti pretul istoric " << i + 1 << ": ";
        cin >> priceHistory[i];
    }
    priceHistory[historySize] = -1;

    Product product(id, name, description, price, priceHistory);

    cout << "Media preturilor: " << product.getPriceAverage(previousprice) << endl;

    Product copie(product);

    double newPrice;
    cout << "Introduceti un nou pret: ";
    cin >> newPrice;
    product.setPrice(newPrice);
    copie.setPrice(newPrice);
    cout << "Media preturilor dupa actualizare: " << product.getPriceAverage(previousprice) << endl;

    cout << "Media preturilor pentru obiectul copiat dupa modificare: " << copie.getPriceAverage(previousprice) << endl;

    delete[] priceHistory;

    return 0;
}
