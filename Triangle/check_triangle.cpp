#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int xp, yp;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> xp >> yp;

    float ab = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    float bc = sqrt(pow(x3-x2,2)+pow(y3-y2,2));
    float ac = sqrt(pow(x3-x1,2)+pow(y3-y1,2));
    
    if (ab + bc == ac || ab + ac == bc || bc + ac == ab) {
        cout << "Given points are collinear!\n";
        return 0;
    }

    int a = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    int a12 = abs(x1*(y2-yp) + x2*(yp-y1) + xp*(y1-y2));
    int a23 = abs(xp*(y2-y3) + x2*(y3-yp) + x3*(yp-y2));
    int a13 = abs(x1*(yp-y3) + xp*(y3-y1) + x3*(y1-yp));

    if (a12 + a23 + a13 == a)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
