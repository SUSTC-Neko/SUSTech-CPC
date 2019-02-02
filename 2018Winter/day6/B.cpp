#include <bits/stdc++.h>
// #include <iostream>
// #include <string.h>
using namespace std;
typedef long long ll;

int main()
{
    double n, x1, y1, x2, y2, x3, y3;
    double a, b, c, k, h;
    double s;
    cin >> n;
    while (n--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        a = (y2 - y1) / ((x2 - x1) * (x2 - x1));
        b = -2 * a * x1;
        c = y1 - a * x1 * x1 - b * x1;
        k = (y2 - y3) / (x2 - x3);
        h = y2 - k * x2;
        s = a / 3 * (x3 * x3 * x3 - x2 * x2 * x2) + (b - k) / 2 * (x3 * x3 - x2 * x2) + (c - h) * (x3 - x2);
        printf("%.2lf\n", s);
    }
}