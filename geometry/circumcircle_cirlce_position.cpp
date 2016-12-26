#include<bits/stdc++.h>
#define in f
#define out cout
using namespace std;

ifstream f("data.in");

struct Point {
  double x;
  double y;
};


struct Ecuation {
    double a;
    double b;
    double c;
};

struct Line {
  Point A1;
  Point A2;

  Line(Point A1, Point A2) {
    this->A1 = A1;
    this->A2 = A2;
  }

  Ecuation getEcuation() {
      double a = (A1.y - A2.y);
      double b = (A2.x - A1.x);
      double c = (A1.x * A2.y - A1.y * A2.x);

      Ecuation retValue;
      retValue.a = a;
      retValue.b = b;
      retValue.c = c;

      return retValue;
  }

};


struct Triangle {
  Point A1;
  Point A2;
  Point A3;

  Triangle(Point A1, Point A2, Point A3) {
    this->A1 = A1;
    this->A2 = A2;
    this->A3 = A3;
  }

  Point getCircumcircleOrigin() {
    //get one
  }
};


int main() {
  //read
  Point A1, A2, A3, P;
  in >> A1.x; in >> A1.y;
  in >> A2.x; in >> A2.y;
  in >> A3.x; in >> A3.y;
  in >> P.x; in >> P.y;

  Triangle triangle(A1, A2, A3);



  return 0;
}
