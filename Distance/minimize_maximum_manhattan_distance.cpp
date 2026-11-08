#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Point {
    int x;
    int y;
};

vector<int> max_manhattan(vector<Point> points, int id) {
    int smin, smax, dmin, dmax;
    int smin_id, smax_id, dmin_id, dmax_id;

    smin_id = smax_id = dmin_id = dmax_id = -1;
    smin = dmin = INT_MAX;
    smax = dmax = INT_MIN;

    for (int i = 0; i < points.size(); i++) {
        if (i == id)
            continue;
        int s = points[i].x + points[i].y;
        int d = points[i].x - points[i].y;

        if (s < smin) {
            smin = s;
            smin_id = i;
        }
        if (s > smax) {
            smax = s;
            smax_id = i;
        }
        if (d < dmin) {
            dmin = d;
            dmin_id = i;
        }
        if (d > dmax) {
            dmax = d;
            dmax_id = i;
        }
    }

    int sdif = abs(smax - smin);
    int ddif = abs(dmax - dmin);

    if (sdif > ddif) {
        return {sdif, smax_id, smin_id};
    } else {
        return {ddif, dmax_id, dmin_id};
    }
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<int> res = max_manhattan(points, -1);
    int id1 = res[1];
    int id2 = res[2];
    int d1 = max_manhattan(points, id1)[0];
    int d2 = max_manhattan(points, id2)[0];

    cout << min(d1, d2) << '\n';

    return 0;
}
