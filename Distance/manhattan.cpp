#include <iostream>
#include <vector>
using namespace std;

struct Pair
{
    int x;
    int y;
};

int manhattan(vector<Pair> points)
{
    int min_sum, max_sum, min_dif, max_dif;
    min_sum = max_sum = points[0].x + points[0].y;
    min_sum = max_sum = points[0].x - points[0].y;

    for (Pair i : points)
    {
        int sum = i.x + i.y;
        int dif = i.x - i.y;
        min_sum = min(min_sum, sum);
        max_sum = max(max_sum, sum);
        min_dif = min(min_dif, dif);
        max_dif = max(max_dif, dif);
    }

    return max(abs(max_sum - min_sum), abs(max_dif - min_dif));
}

int main()
{
    vector<Pair> points = {{0, 1}, {2, 3}, {9, 12}};
    int result = manhattan(points);
    cout << result << "\n";
    return 0;
}
