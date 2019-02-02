#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int angle, s, k, n;
        cin >> angle;
        s = __gcd(180, angle);
        k = angle / s;
        n = 180 / s;
        int m = n;
        while (m < k + 2)
        {
            m += n;
        }
        printf("%d\n", m);
    }
}