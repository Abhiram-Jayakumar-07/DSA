#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

bool do_you_overlap(Point l1, Point r1, Point l2, Point r2)
{
    if (l2.x > r1.x || l1.x > r2.x)
        return false;
    if (l2.y > r1.y || l1.y > r2.y)
        return false;
    return true;
}

int main()
{
    Point l1, r1, l2, r2;

    cin >> l1.x >> l1.y;
    cin >> r1.x >> r1.y;
    cin >> l2.x >> l2.y;
    cin >> r2.x >> r2.y;

    cout << do_you_overlap(l1, r1, l2, r2);

    return 0;
}