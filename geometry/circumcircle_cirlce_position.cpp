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
  // position vector
  Point position;
  // offset by the origin
  Point offset;

  Ecuation(Point a, Point b) {
    position = Point(b.x - a.x, b.y - a.y);
    offset = a;
  }

  Point getIntersection(Ecuation ecuation) {
    double a1 = position.x;
    double a2 = position.y;
    double x1 = offset.x;
    double x2 = ecuation.offset.x;
    double y1 = offset.y;
    double y2 = ecuation.offset.y;
    double a3 = ecuation.position.x;
    double a4 = ecuation.position.y;
    double t1 = ((a3 * (y2 - y1)) - (a4 * (x2 - x1))) / (a2 * a3 - a1 * a4);
    return Point(t1 * position.x + offset.x, t1 * position.y + offset.y);
  }
};

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

  Line() {}

  Ecuation getMediator() {
    double midX = (A1.x + A2.x) / 2;
    double midY = (A1.y + A2.y) / 2;
    Ecuation ecuation(A1, A2);
    ecuation.position = Point(ecuation.position.y * -1, ecuation.position.x);
    ecuation.offset = Point(midX, midY);
    return ecuation;
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

  Point getOrigin() {
    Ecuation firstMediator = A1A2.getMediator();
    Ecuation secondMediator = A2A3.getMediator();

    // cout << firstMediator.position.x << " " << firstMediator.position.y <<
    // endl;
    // cout << secondMediator.position.x << " " << secondMediator.position.y
    //     << endl;

    Point origin = firstMediator.getIntersection(secondMediator);
    return origin;
  }

  string isInsideCircle(Point p) {
    Point circleOrigin = getOrigin();
    double radius = getDistance(circleOrigin, A1);

    if (abs(radius - getDistance(p, circleOrigin)) <= EPS) {
      return "The point is on circle ";
    }

    if (getDistance(p, circleOrigin) <= radius + EPS)
      return "The point is inside";
    return "The point is outside.";
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

  out << triangle.isInsideCircle(P) << endl;
  out << "ORIGIN " << triangle.getOrigin().x << " " << triangle.getOrigin().y
      << endl;

  Point A = A1;
  Point B = A2;
  Point C = A3;
  Point D = P;

  Line AB(A, B);
  Line CD(C, D);

  Line AD(A, D);
  Line BC(B, C);

  if (abs(getDistance(A, B) + getDistance(C, D)) -
          (getDistance(A, D) + getDistance(B, C)) <=
      EPS) {
    out << "circumscriptible\n";
  } else {
    out << "not circumscriptible \n";
  }

  return 0;
}
