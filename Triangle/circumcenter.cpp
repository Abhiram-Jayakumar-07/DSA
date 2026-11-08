#include <iostream>
using namespace std;

struct Line {
  double a;
  double b;
  double c;
};

Line line_from_points(double x1, double y1, double x2, double y2) {
  Line l;
  l.a = y2 - y1;
  l.b = x1 - x2;
  l.c = l.a * x1 + l.b * y1;
  return l;
}

Line perpendicular_bisector(double x1, double y1, double x2, double y2, Line l) {
  Line pb;
  double x = (x1 + x2) / 2;
  double y = (y1 + y2) / 2;
  pb.a = -l.b;
  pb.b = l.a;
  pb.c = pb.a * x + pb.b * y;
  return pb;
}

int main() {
  double x1, y1;
  double x2, y2;
  double x3, y3;

  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;

  Line l1 = line_from_points(x1, y1, x2, y2);
  Line l2 = line_from_points(x2, y2, x3, y3);

  Line pb1 = perpendicular_bisector(x1, y1, x2, y2, l1);
  Line pb2 = perpendicular_bisector(x2, y2, x3, y3, l2);

  double det = pb1.a * pb2.b - pb2.a * pb1.b;
  double x = (pb2.b * pb1.c - pb1.b * pb2.c) / det;
  double y = (pb1.a * pb2.c - pb2.a * pb1.c) / det;

  cout << x << '\n';
  cout << y << '\n';

  return 0;
}
