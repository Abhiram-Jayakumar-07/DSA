#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x;
    long long y;
};

long long manhattan(vector<Point> points) {
    long long sum = 0;
    for (int i = 0; i < points.size()-1; i++)
        for (int j = i+1; j < points.size(); j++)
            sum += abs(points[i].x-points[j].x) + abs(points[i].y-points[j].y);
    return sum;
}

int main() {
    vector<Point> points;

    int n;
    long long x, y;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    long long dist = manhattan(points);
    cout << dist << "\n";

    return 0;
}