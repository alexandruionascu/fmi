#include<bits/stdc++.h>
#define in fin
#define out cout
#define EPS 0.000000001
using namespace std;

ifstream fin("data.in");

vector< pair<int, int> > polygon;

void read() {
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;
    in >> x1; in >> y1;
    in >> x2; in >> y2;
    in >> x3; in >> y3;
    in >> x4; in >> y4;

    polygon.push_back({x1, y1});
    polygon.push_back({x2, y2});
    polygon.push_back({x3, y3});
    polygon.push_back({x4, y4});
}

int f(vector<pair<int, int>>& polygon, int i, int j, int x, int y) {
    int first = (x * polygon[i].second + polygon[i].first * polygon[j].second + y * polygon[j].first);
    int second = (polygon[i].second * polygon[j].first  + polygon[j].second * x + y * polygon[i].first);

    return first - second;
}

bool sameSide(vector<pair<int, int>>&polygon, int a0, int a1, int a2, int a3) {
    if(f(polygon, a0, a1, polygon[a2].first, polygon[a2].second) * f(polygon, a0, a1, polygon[a3].first, polygon[a3].second) > 0)
        return true;
    else
        return false;
}

bool isConvex(vector<pair<int, int>>& polygon) {
    bool isConvex = true;
    isConvex = isConvex && sameSide(polygon, 0, 1, 2, 3);
    isConvex = isConvex && sameSide(polygon, 0, 3, 1, 2);

    return isConvex;
}

double getArea(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    int first = A.first * B.second + B.first * C.second + A.second * C.first;
    int second = B.second * C.first + C.second * A.first + A.second * B.first;

    return abs(first - second);
}

void isInside() {
    if(getArea(polygon[0], polygon[1], polygon[2]) + getArea(polygon[0], polygon[1], polygon[3]) + getArea(polygon[0], polygon[2], polygon[3]) == getArea(polygon[1], polygon[2], polygon[3]))
        out << endl << "Point is inside" << endl;
    else if(getArea(polygon[1], polygon[0], polygon[2]) + getArea(polygon[1], polygon[0], polygon[3]) + getArea(polygon[1], polygon[2], polygon[3]) == getArea(polygon[0], polygon[2], polygon[3]))
        out << endl << "Point is inside" << endl;
    else if(getArea(polygon[2], polygon[0], polygon[1]) + getArea(polygon[2], polygon[0], polygon[3]) + getArea(polygon[2], polygon[1], polygon[3]) == getArea(polygon[1], polygon[0], polygon[3]))
        out << endl << "Point is inside" << endl;
    else if(getArea(polygon[3], polygon[0], polygon[1]) + getArea(polygon[3], polygon[0], polygon[2]) + getArea(polygon[3], polygon[1], polygon[2]) == getArea(polygon[0], polygon[1], polygon[2]))
        out << endl << "Point is inside" << endl;
    else
      out << endl << "Point is not inside" << endl;
}



int main() {
    read();

    if(isConvex(polygon)) {
        out << "is convex";
    } else {
        out << "not convex";
    }

    isInside();

    return 0;
}
