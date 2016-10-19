#include<bits/stdc++.h>
#define in cin
#define out cout
#define eps 0.0000000001
using namespace std;

ifstream f("wow.in");

int main() {
    string s;
    in >> s;
    long double powerUp;
    in >> powerUp;
    in >> s;
    long double multiply;
    in >> multiply;
    long double evolvedPowerUp;
    in >> evolvedPowerUp;
    long double newPowerUp = powerUp * multiply;

    if(evolvedPowerUp - newPowerUp >= -eps && evolvedPowerUp - newPowerUp <= eps) {
        out << "Whatever";
    } else if(newPowerUp > evolvedPowerUp) {
        out << "Power up, Evolve";
    } else if(newPowerUp < evolvedPowerUp) {
        out << "Evolve, Power up";
    }

    return 0;
}
