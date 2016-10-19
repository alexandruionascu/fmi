#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;


ifstream f("date.in");

int n;
string ugly = "";
unsigned long long p;
bool zero = false;

bool isBeautiful(string number) {

    if(number.size() == 1 && number[0] == '0') {
        zero = true;
    }

    int ones = 0;
    for(int i = 0; i < number.size(); i++) {
        if(number[i] != '0' && number[i] != '1') {
            return false;
        }

        if(number[i] == '1') {
            ones++;
        }

    }

    if(ones > 1) {
        return false;
    }

    for(int i = 0; i < number.size(); i++) {
        if(number[i] == '0' && ones > 0) {
            p++;
        }
    }


    return true;
}

void read() {
    in >> n;
    string number;
    for(int i = 1; i <= n; i++) {
        in >> number;
        if(isBeautiful(number) == false) {
            ugly = number;
        }
    }
}

void solve() {

    if(zero == true) {
        out << 0;
        return;
    }

    if(ugly.size() == 0) {
        out << "1";
    } else {
        bool zero = true;
        for(int i = 0; i < ugly.size(); i++) {
            if(ugly[i] != '0') {
                zero = false;
            }

            if(!zero) {
                out << ugly[i];
            }
        }
    }

    for(int i = 1; i <= p; i++) {
        out << '0';
    }
}

int main() {
    read();
    solve();
    return 0;
}
