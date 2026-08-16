#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x1, y1;
    int x2, y2;
    int x3, y3;
    
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    
    float ab = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    float bc = sqrt(pow(x3-x2,2)+pow(y3-y2,2));
    float ac = sqrt(pow(x3-x1,2)+pow(y3-y1,2));
    
    if (ab + bc == ac || ab + ac == bc || bc + ac == ab)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}