#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

bool check_collinear(vector<Point> points) {
    if (points.size() <= 1) return true;

    int ref = 1;
    while (ref < points.size() 
        && points[0].x == points[ref].x 
        && points[0].y == points[ref].y) {
            ref++;
    }

    if (ref == points.size()) return true;

    int xdif = points[ref].x - points[0].x;
    int ydif = points[ref].y - points[0].y;

    for (int i = 1; i < points.size(); i++) {
        int curr_xdif = points[i].x - points[i-1].x;
        int curr_ydif = points[i].y - points[i-1].y;
        if (ydif*curr_xdif != xdif*curr_ydif)
            return false;
    }
    return true;
}

int main() {
    int n, x, y;
    vector<Point> points;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    cout << check_collinear(points) << "\n";

    return 0;
}