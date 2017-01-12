#include <bits/stdc++.h>
#define in f
#define out cout
#define EPS 0.000000001
using namespace std;

ifstream f("data.in");

struct Point {
  double x;
  double y;

  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }

  Point() {}
};

struct Ecuation {
  double a;
  double b;
  double c;

  void printEcuation() {
    cout << "a: " << a << " b: " << b << " c: " << c << "\n";
  }
};

double getDeterminant(Point A, Point B) {
  return A.x * B.y - A.y * B.x;
}
bool isEqual(double a, double b) {
  if (abs(a - b) <= EPS)
    return true;
  else
    return false;
}

Point getIntersection(Ecuation ecA, Ecuation ecB) {
  int determinant = getDeterminant({ecA.a, ecA.b}, {ecB.a, ecB.b});

  double x =
      (double)-1 * (double)getDeterminant({ecA.c, ecA.b}, {ecB.c, ecB.b});
  x /= (double)determinant;
  double y =
      (double)-1 * (double)getDeterminant({ecA.a, ecA.c}, {ecB.a, ecB.c});
  y /= (double)determinant;
  return Point(x, y);
}

double getDistance(Point A, Point B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

struct Line {
  Point A1;
  Point A2;

  Line(Point A1, Point A2) {
    this->A1 = A1;
    this->A2 = A2;
  }

  double getSlope() {
    if (A1.y == A2.y)
      return 0;
    if (A1.x == A2.x)
      return 0;
    return (A2.y - A1.y) / (A2.x - A1.x);
  }

  void printEcuation() { getEcuation().printEcuation(); }

  Line() {}

  Ecuation getEcuation() {
    Ecuation retValue;

    if (A1.x == A2.x) {
      retValue.a = 1;
      retValue.b = 0;
      retValue.c = -(A2.x);
    } else if (A1.y == A2.y) {
      retValue.a = 0;
      retValue.b = 1;
      retValue.c = -(A2.y);
    } else {
      retValue.a = getSlope();
      retValue.b = -1;
      retValue.c = (A2.y - getSlope() * A2.x);
    }
    return retValue;
  }

  Ecuation getPerpendicularEcuation() {
    Ecuation ec = getEcuation();
    double slope = getSlope();
    if (slope == 0) {
      ec.a = 1;
      ec.b = 0;
      ec.c = (double)-1 * ((A1.x + A2.x) / 2);
      return ec;
    }

    slope = (double)-1 / getSlope();
    ec.a = slope;
    ec.b = -1;
    ec.c = ((A1.y + A2.y) / 2) - slope * ((A1.x + A2.x) / 2);
    return ec;
  }
};

struct Triangle {
  Point A1;
  Point A2;
  Point A3;

  Line A1A2;
  Line A2A3;
  Line A1A3;

  Triangle(Point A1, Point A2, Point A3) {
    this->A1 = A1;
    this->A2 = A2;
    this->A3 = A3;
    this->A1A2 = Line(A1, A2);
    this->A2A3 = Line(A2, A3);
    this->A1A3 = Line(A1, A3);
  }

  Point getCircumcircleOrigin() {
    Line firstLine = Line(A1, A2);
    Ecuation firstMediator = firstLine.getPerpendicularEcuation();
    Line secondLine = Line(A2, A3);
    Ecuation secondMediator = secondLine.getPerpendicularEcuation();
    return getIntersection(firstMediator, secondMediator);
  }

  bool isInsideCircle(Point p) {
    Point circleOrigin = getCircumcircleOrigin();
    double radius = getDistance(circleOrigin, A1);
    if (getDistance(p, circleOrigin) <= radius + EPS)
      return true;
    return false;
  }
};

int main() {
  // read
  Point A1, A2, A3, P;
  in >> A1.x;
  in >> A1.y;
  in >> A2.x;
  in >> A2.y;
  in >> A3.x;
  in >> A3.y;
  in >> P.x;
  in >> P.y;

  Triangle triangle(A1, A2, A3);

  Point origin = triangle.getCircumcircleOrigin();
  if (triangle.isInsideCircle(P))
    out << "The Point is inside circumcircle. \n";
  else
    out << "The Point is outside circumcircle. \n";

  return 0;
}
