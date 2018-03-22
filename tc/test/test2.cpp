#include <iostream>
using namespace std;

typedef struct Point {
    int x;
    int y;
};

int f(int x) {
    return 23 * x;
}

int main() {
    /* we have two points 
        (1, 2) and (3, 4)*/
    Point points[] = { {1, 2}, {3, 4}};
    cout << "Hello";
}