#include <bits/stdc++.h>
#define in f
#define out cout
#define EPS 0.000000001
using namespace std;

ifstream f("data.in");

struct Ecuation {
  double a;
  double b;
  double c;
};

void printEcuation(Ecuation &ec) {
  out << ec.a << " * x + " << ec.b << " * y + " << ec.c << " = 0\n";
}

Ecuation getEcuation(pair<double, double> A, pair<double, double> B) {
  double a = (A.second - B.second);
  double b = (B.first - A.first);
  double c = (A.first * B.second - A.second * B.first);

  Ecuation retValue;
  retValue.a = a;
  retValue.b = b;
  retValue.c = c;

  return retValue;
}

bool isEqual(double a, double b) {
  if (abs(a - b) <= EPS)
    return true;
  else
    return false;
}

bool isInRange(pair<double, double> X,
               pair<pair<double, double>, pair<double, double>> R) {
  if (X.first >= min(R.first.first, R.second.first)) {
    if (X.second <= max(R.first.second, R.second.second)) {
      return true;
    }
  }
  return false;
}

double getDeterminant(pair<double, double> A, pair<double, double> B) {
  return A.first * B.second - A.second * B.first;
}

double getDistance(pair<double, double> A, pair<double, double> B) {
  return sqrt((A.first - B.first) * (A.first - B.first) +
              (A.second - B.second) * (A.second - B.second));
}

bool isInsideSegment(pair<double, double> point,
                     pair<pair<double, double>, pair<double, double>> segment) {
  if (isEqual(getDistance(point, segment.first) +
                  getDistance(point, segment.second),
              getDistance(segment.first, segment.second)))
    return true;
  else
    return false;
}

int main() {
  pair<pair<double, double>, pair<double, double>> A;
  pair<pair<double, double>, pair<double, double>> B;
  double x1, y1, x2, y2;
  in >> x1;
  in >> y1;
  in >> x2;
  in >> y2;
  A = {{x1, y1}, {x2, y2}};
  in >> x1;
  in >> y1;
  in >> x2;
  in >> y2;
  B = {{x1, y1}, {x2, y2}};

  Ecuation ecA = getEcuation(A.first, A.second);
  Ecuation ecB = getEcuation(B.first, B.second);

  int determinant = getDeterminant({ecA.a, ecA.b}, {ecB.a, ecB.b});

  if (determinant != 0) {
    double x =
        (double)-1 * (double)getDeterminant({ecA.c, ecA.b}, {ecB.c, ecB.b});
    x /= (double)determinant;
    double y =
        (double)-1 * (double)getDeterminant({ecA.a, ecA.c}, {ecB.a, ecB.c});
    y /= (double)determinant;
    out << x << " " << y << endl;
    if (isInsideSegment({x, y}, A) && isInsideSegment({x, y}, B))
      out << "Intersect in " << x << " " << y << " " << endl;
    else
      out << "Intersect outside of the segment" << endl;

  } else {
    int detA = getDeterminant({ecA.a, ecA.b}, {ecB.a, ecB.b});
    int detB = getDeterminant({ecA.b, ecA.c}, {ecB.b, ecB.c});

    if (detA != 0 || detB != 0) {
      out << "No intersection" << endl;
    } else {
      // they are on the same line
      out << "Points are on the same line" << endl;
      if (!(isInsideSegment(B.first, A) || isInsideSegment(B.second, A))) {
        out << "No intersection" << endl;
      } else {
        out << "(" << max(A.first.first, B.first.first) << ", "
            << max(A.first.second, B.first.second) << ") ("
            << min(A.second.first, B.second.first) << ", "
            << min(A.second.second, B.second.second) << ")" << endl;
      }
    }
  }

  return 0;
}
