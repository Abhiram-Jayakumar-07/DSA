#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair
{
    int x;
    int y;
};

int klee(vector<Pair> segments)
{
    vector<Pair> points;
    for (Pair i : segments)
    {
        points.push_back({i.x, 1});
        points.push_back({i.y, 0});
    }

    sort(points.begin(), points.end(), [](Pair a, Pair b)
         {
        if (a.x == b.x)
            return a.y < b.y;
        else
            return a.x < b.x; });

    int result = 0, count = 1;
    for (int i = 1; i < points.size(); i++)
    {
        if (count > 0)
            result += points[i].x - points[i - 1].x;
        
        if (points[i].y == 1)
            count++;
        else
            count--;
    }

    return result;
}

int main()
{
    vector<Pair> segments = {{0, 1}, {2, 3}, {9, 12}};
    int result = klee(segments);
    cout << result << "\n";
    return 0;
}
