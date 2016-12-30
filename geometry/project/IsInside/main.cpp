#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;

namespace {
const string not_inside_or_on_sides = "Nu e in poligon ,nici pe laturi";
const string on_sides = "E pe latura";
const string point_inside = "Punctul e in interior";
const string point_outside = "Punctul e in exterior";
const double eps = 0.0000000001;
}

double det(pair<double, double> p1, pair<double, double> p2,
           pair<double, double> p3) {
  p2 = {p2.first - p1.first, p2.second - p1.second};
  p3 = {p3.first - p1.first, p3.second - p1.second};

  return p3.first * p2.second - p3.second * p2.first;
}

bool compx(pair<double, double> p1, pair<double, double> p2) {
  double my_det = det({0, 0}, p1, p2);
  if (my_det == 0) {
    return p1 < p2;
  }
  return det < 0;
}

void re_order(vector<pair<double, double>> &pol) {
  random_shuffle(pol.begin(), pol.end());
  for (int i = 1; i < pol.size(); ++i) {
    pol[i] = {pol[i].first - pol[0].first, pol[i].second - pol[0].second};
  }

  sort(pol.begin() + 1, pol.end(), compx);
  for (int i = 1; i < pol.size(); ++i) {
    pol[i] = {pol[i].first + pol[0].first, pol[i].second + pol[0].second};
  }
}

bool is_on_seg(pair<double, double> p1, pair<double, double> p2,
               pair<double, double> p3) {
  if (det(p1, p2, p3) == 0) {
    if (p3.first >= min(p1.first, p2.first) &&
        p3.first <= max(p1.first, p2.first)) {
      if (p3.second >= min(p1.second, p2.second) &&
          p3.second <= max(p1.second, p2.second)) {
        return true;
      }
    }
  }
  return false;
}
double mdl(double val) { return ((val < 0.0) ? -val : val); }

double area(pair<double, double> p1, pair<double, double> p2,
            pair<double, double> p3) {
  return mdl(det(p1, p2, p3));
}

bool is_equal_eps(double v1, double v2) {
  double val = v1 - v2;
  bool res = (val >= -eps && val <= eps);
  return res;
}

bool is_point_inside_triangle(pair<double, double> p1, pair<double, double> p2,
                              pair<double, double> p3,
                              pair<double, double> point) {

  double a1 = area(p1, p2, point);
  double a2 = area(p2, p3, point);
  double a3 = area(p3, p1, point);
  double area_total = area(p1, p2, p3);
  return (is_equal_eps(a1 + a2 + a3, area_total));
}

string to_str(pair<double, double> point) {
  return "(" + to_string(point.first) + "," + to_string(point.second) + ")";
}

pair<bool, string> is_on_sides(vector<pair<double, double>> &pol,
                               pair<double, double> point) {
  for (int i = 0; i < pol.size(); ++i)
    if (is_on_seg(pol[i], pol[(i + 1) % pol.size()], point) == 1) {
      return {true, ("" + on_sides + to_str(pol[i]) + " " +
                     to_str(pol[(i + 1) % pol.size()]))};
    }

  return make_pair(false, "");
}

bool sign(double val) { return (val <= 0.0); }

#define ppair(x) cout << x.first << " " << x.second << '\n';

string solve(vector<pair<double, double>> &pol, pair<double, double> point) {
  re_order(pol);
  if (is_on_sides(pol, point).first) {
    return is_on_sides(pol, point).second;
  }

  if (det(pol[0], pol[1], point) * det(pol[0], pol.back(), point) > 0) {
    return not_inside_or_on_sides;
  }

  for (int i = 2; i < pol.size() - 1; ++i) {
    if (is_on_seg(pol[0], pol[i], point)) {
      return point_inside;
    }
    if (det(pol[0], pol[i], point) == 0.0) {
      return point_outside;
    }
  }

  int left = 1, right = pol.size() - 1;

  while (left - right > 1) {
    int mid = (left + right) / 2;

    if (sign(det(pol[0], pol[mid], point)) ==
        sign(det(pol[0], pol[1], point))) {
      left = mid;
    } else {
      right = mid;
    }
  }

  if (is_point_inside_triangle(pol[0], pol[left], pol[left + 1], point)) {
    return point_inside;
  }

  return point_outside;
}

vector<pair<double, double>> poligon;

const int WIDTH = 1280;
const int HEIGHT = 720;
const int INITIAL_X = -50;
const int INITIAL_Y = -50;

vector<sf::CircleShape> points;
CircleShape externPoint(10.0f);
Texture wallTexture;
int pointIndex = 0;

void init(ConvexShape &polygon) {
  polygon.setFillColor(Color::Blue);
  polygon.setOutlineColor(Color::Red);
  polygon.setOutlineThickness(3.0f);
  polygon.setPointCount(0);
  externPoint.setFillColor(Color::Magenta);
  // cout << "CODE " << wallTexture.loadFromFile("wall.jpg") << endl;
}

void handleClick(RenderWindow &window) {
  // left mouse button is pressed: shoot
  sf::Vector2i localPosition = sf::Mouse::getPosition(window);
  if (localPosition.x <= 0 || localPosition.y <= 0)
    return;
  if (localPosition.x >= WIDTH || localPosition.y >= HEIGHT)
    return;
  sf::CircleShape point(10.f);
  point.setPosition(localPosition.x, localPosition.y);
  point.setFillColor(Color::Red);
  points.push_back(point);
  pointIndex++;
}

void handleRightClick(RenderWindow &window) {
  Vector2i localPosition = sf::Mouse::getPosition(window);
  externPoint.setPosition(Vector2f(localPosition.x, localPosition.y));
}

void update(RenderWindow &window) {
  window.clear();

  ConvexShape polygon;
  init(polygon);
  polygon.setPointCount(points.size());
  int index = 0;
  for (auto point : points) {
    polygon.setPoint(index, point.getPosition());
    index++;
  }

  window.draw(polygon);

  if (points.size() <= 2) {
    for (auto point : points) {
      window.draw(point);
    }
  }

  for (int i = 1; i < points.size(); i++) {
    sf::Vertex line[] = {sf::Vertex(points[0].getPosition()),
                         sf::Vertex(points[i].getPosition())};
    window.draw(line, 2, sf::Lines);
  }

  vector<pair<double, double>> poligon;
  for (auto p : points) {
    poligon.push_back(make_pair(p.getPosition().x, p.getPosition().y));
  }

  pair<double, double> pos;
  pos.first = externPoint.getPosition().x;
  pos.second = externPoint.getPosition().y;
  if (poligon.size() >= 3) {
    string response = solve(poligon, pos);
    Text status;
    cout << response << endl;
    status.setColor(Color::White);
    status.setString(response);

    status.setCharacterSize(24);
    window.draw(status);
  }

  window.draw(externPoint);
  window.display();
}

void clear() { points.clear(); }
void renderWindow(RenderWindow &window) {
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (Mouse::isButtonPressed(Mouse::Left)) {
        handleClick(window);
      }

      if (Mouse::isButtonPressed(Mouse::Right)) {
        handleRightClick(window);
      }

      if (Keyboard::isKeyPressed(Keyboard::C)) {
        clear();
      }
      update(window);
    }
  }
}

int main() {
  externPoint.setPosition(INITIAL_X, INITIAL_Y);
  ContextSettings settings;
  settings.antialiasingLevel = 8;
  RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Relative Position",
                      Style::Default, settings);
  renderWindow(window);
  return 0;
}
