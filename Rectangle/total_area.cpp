#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

int area(Point l1, Point r1, Point l2, Point r2)
{
    int area1 = (r1.x - l1.x) * (r1.y - l1.y);
    int area2 = (r2.x - l2.x) * (r2.y - l2.y);

    int area12;
    if (l2.x >= r1.x || l1.x >= r2.x || l2.y >= r1.y || l1.y >= r2.y)
        area12 = 0;
    else
        area12 = (min(r1.x, r2.x) - max(l1.x, l2.x)) * (min(r1.y, r2.y) - max(l1.y, l2.y));

    return area1 + area2 - area12;
}

int main()
{
    Point l1, r1, l2, r2;

    cin >> l1.x >> l1.y;
    cin >> r1.x >> r1.y;
    cin >> l2.x >> l2.y;
    cin >> r2.x >> r2.y;

    cout << area(l1, r1, l2, r2);

    return 0;
}
