#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

int manhattan(vector<Point> points) {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
    });

    return abs(points.back().x - points[0].x) + abs(points.back().y - points[0].y);
}

int main() {
    vector<Point> points;

    int n;
    int x, y;

    cout << "Enter the number of points: ";
    cin >> n;
    cout << "Enter the x and y coordinates, respectively:\n";

    for (int i = 0; i < n; i++) {
        cin >> x;
        cin >> y;
        points.push_back({x, y});
    }

    int dist = manhattan(points);
    cout << "Maximum Manhattan distance = " << dist << "\n";

    return 0;
}