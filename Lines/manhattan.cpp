#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

int manhattan(vector<Point> points) {
    int min_sum, max_sum, min_dif, max_dif;
    
    min_sum = max_sum = points[0].x + points[0].y;
    min_dif = max_dif = points[0].x - points[0].y;

    Point min_s, max_s, min_d, max_d;

    for (Point i: points) {
        int sum = i.x + i.y;
        int dif = i.x - i.y;

        if (min_sum > sum) {
            min_sum = sum;
            min_s.x = i.x;
            min_s.y = i.y;
        }
        if (max_sum < sum) {
            max_sum = sum;
            max_s.x = i.x;
            max_s.y = i.y;
        }
        if (min_dif > dif) {
            min_dif = dif;
            min_d.x = i.x;
            min_d.y = i.y;
        }
        if (max_dif < dif) {
            max_dif = dif;
            max_d.x = i.x;
            max_d.y = i.y;
        }
    }

    Point m, s;
    if (max_sum-min_sum > max_dif-min_dif) {

    }
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