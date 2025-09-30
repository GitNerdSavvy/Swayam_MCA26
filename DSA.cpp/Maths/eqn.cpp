#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a * b);
    return d;
}
int main()
{
    // 2x + 4y = 8
    int a = 2, b = 4, c = 8;
    int x0, y0;
    int g = gcd(a, b, x0, y0);

    if (c % g != 0)
    {
        cout << "No solution exists\n";
        return 0;
    }

    int x = x0 * (c / g);
    int y = y0 * (c / g);

    cout << "One solution: x = " << x << ", y = " << y << "\n";

    // General solution:
    cout << "General solution: x = " << x << " + " << (b / g) << "t, y = " << y << " - " << (a / g) << "t, for integer t\n";
}