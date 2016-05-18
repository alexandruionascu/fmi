#include<bits/stdc++.h>
using namespace std;

namespace std {
    template < typename T > std::string to_string( const T& n ) {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
};

class Product {
    private:
        string name;

    public:
        Product(string& name) {
            this->name = name;
        }
};

class Date {

    int day;
    int month;
    int year;

    public:
        Date(int day, int month, int year) {
            this->day = day;
            this->month = month;
            this->year = year;
        }

        string getDate() {
            return to_string(day) + "-" +to_string(month) + "-" + to_string(year);
        }

        bool isBetween(Date* date1, Date* date2) {

            if(date1->toDays() <= toDays() && toDays() <= date2->toDays()) {
                return true;
            } else return false;
        }

        int toDays() {
            return year * 365 + month * 30 + day;
        }

};

class StockEntry {

    private:
        string productName;
        int quantity;
        Date* date;
        int valability;
        int price;
        int discount;

    public:
        StockEntry(int id, Date* date, string productName, int quantity, int price, int discount, int valability = 0 ) {
            this->date = date;
            this->productName = productName;
            this->quantity = quantity;
            this->price = price;
            this->discount = discount;
            this->valability = valability;
        }

        void printStockEntry() {
            cout << date->getDate() << " -> " << productName << " " << "quantity: " << quantity << " price: " << price <<" discount: " << "valability: " << valability << "\n";
        }

        //getter
        Date* getDate() const {
            return date;
        }

        int getValability() const {
            return valability;
        }

        int getQuantity() const {
            return quantity;
        }

        int getPrice() const {
            return price;
        }

        void setQuantity(int quantity) {
            this->quantity = quantity;
        }

        string getProductName() const {
            return productName;
        }

        ~StockEntry() {
            delete date;
        }

};



class Shop {
    private:
        unordered_map<string, bool> products;
        vector<StockEntry*> entries;
        int currentId = 0;

    public:
        static const int DAY = 18;
        static const int MONTH = 5;
        static const int YEAR = 2016;

        void addProduct(string name) {
            products[name] = true;
        }

        void printProducts() {
            for(auto product : products) {
                cout << product.first << " ";
            }

            cout << "\n";
        }

        void addStockEntry(int day, int month, int year, string product, int quantity, int price, int discount, int valability = 0) {
            auto stockEntry = new StockEntry(currentId, new Date(day, month, year), product, quantity, price, discount, valability);
            currentId++;
            entries.push_back(stockEntry);
        }

        void printStockEntries() {
            for(auto entry : entries) {
                entry->printStockEntry();
            }
        }

        void printStockEntries(int day1, int month1, int year1, int day2, int month2, int year2) {
            auto date1 = new Date(day1, month1, year1);
            auto date2 = new Date(day2, month2, year2);

            for(auto entry : entries) {
                if(entry->getDate()->isBetween(date1, date2) == true) {
                    entry->printStockEntry();
                }
            }

            delete date1;
            delete date2;
        }

        void printAvailableProducts() {
            for(auto entry : entries) {
                if(entry->getDate()->toDays() + entry->getValability() > Date(Shop::DAY, Shop::MONTH, Shop::YEAR).toDays() && entry->getQuantity() > 0) {
                    entry->printStockEntry();
                }
            }
        }

        void sell(string product, int quantity) {

            sort(entries.begin(), entries.end(), [&](StockEntry* a, StockEntry* b) {
                    return a->getPrice() < b->getPrice();
            });

            for(auto entry : entries) {
                if(entry->getQuantity() >= quantity && entry->getProductName() == product) {
                    cout << "Sale successful : " << quantity * entry->getPrice() << "\n";
                    entry->setQuantity(entry->getQuantity() - quantity);
                    return;
                }
            }

            // no success
            cout << "Not enough stock but here are the options: " << "\n";
            for(int i = 0; i < entries.size(); i++) {
                if(entries[i]->getProductName() == product) {
                    entries[i]->printStockEntry();
                }
            }
        }

        ~Shop() {
            for(int i = 0; i < entries.size(); i++)
                delete entries[i];
        }



};



int main() {

    auto shop = new Shop();

    bool close = false;
    cout << "Welcome to the store! \n";
    int operation;

    while(!close) {
        cout << "To add a product press 1 \n";
        cout << "To add a stock entry press 2 \n";
        cout << "To print all products press 3 \n";
        cout << "To print stock entries between two dates, press 4 \n";
        cout << "To sell a product press 5 \n";
        cout << "To print all available products press 6 \n";
        cout << "To close press any other key \n";

        cin >> operation;

        if(operation == 1) {
            string s;
            cout << "Name of product ";
            cin >> s;
            shop->addProduct(s);

        } else if(operation == 2) {
            cout << "Day ";
            int day, month, year;
            cin >> day;
            cout << "Month ";
            cin >> month;
            cout << "Year ";
            cin >> year;
            string s;
            cout << "Name of product ";
            cin >> s;
            int quantity, price, valability, discount;
            cout << "Quantity ";
            cin >> quantity;
            cout << "Price ";
            cin >> price;
            cout << "Discount ";
            cin >> discount;

            cout << "Valability ";
            cin >> valability;

            shop->addStockEntry(day, month, year, s, quantity, price, discount, valability);

        } else if(operation == 3) {
            shop->printProducts();
        } else if(operation == 4) {
            int day1, day2, month1, month2, year1, year2;

            cout << "Day of First Date ";
            cin >> day1;

            cout << "Month of first date ";
            cin >> month1;

            cout << "Year of the first date ";
            cin >> year1;

            cout << "Day of second Date ";
            cin >> day1;

            cout << "Month of second date ";
            cin >> month1;

            cout << "Year of the second date ";
            cin >> year1;
        } else if(operation == 5) {
            string s;
            cout << "Product ";
            cin >> s;
            int quqntity;
            cout << "Quantity ";
            cin >> quantity;

            shop->sell(s, quantity);
        } else if(operation == 6) {

        } else {
            close = true;
        }

    }


    shop->addStockEntry(10, 4, 2016, "cirese", 10, 15, 10, 3);

    shop->addStockEntry(20, 4, 2016, "mere", 20, 20, 14, 4);



    shop->printStockEntries(10, 4, 2016, 5, 9, 2016);

    shop->sell("mere", 10);

    shop->printStockEntries();

    delete shop;

    return 0;
}
