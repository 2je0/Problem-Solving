#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Point
{
    int x;
    int y;
    int z;
    Point(int x = -1, int y = -1, int z = -1) : x(x), y(y), z(z) {}
    bool operator<(const Point &p) const
    {
        if (z != p.z)
            return z < p.z; // z 오름차순
        if (y != p.y)
            return y < p.y;
        if (x != p.x)
            return x < p.x;
    }
};
int main()
{
    vector<Point> v;
    v.push_back(Point(2, 2, 3));
    v.push_back(Point(1, 2, 5));
    sort(v.begin(), v.end());
    for (auto &ele : v)
    {
        cout << ele.x << " " << ele.y << " " << ele.z << endl;
    }

    return 0;
}