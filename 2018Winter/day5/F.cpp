#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265
int n;
double a, b, l, r, ans;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> l >> r;
        ans = 0;
        int x = r;
        ans += 0.5 * b * a * (asin(x / a) + 0.5 * sin(2 * asin(x / a)));
        x = l;
        ans -= 0.5 * b * a * (asin(x / a) + 0.5 * sin(2 * asin(x / a)));
        printf("%.3f\n", 2 * ans);
    }
    return 0;
}
