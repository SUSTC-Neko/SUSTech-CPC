// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[60][60];

int main()
{
    memset(a, 0, sizeof(a));
    a[0][0] = 1;
    a[1][0] = 1;
    a[1][1] = 1;

    for (int i = 2; i <= 60; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }

    int n;
    while (~scanf("%d", &n))
    {
        ll ans = 0;
        for (int i = 1;; i++)
        {
            if ((i - 1) * 3 + 1 > n) // 一个占3块砖
                break;
            ans += a[n - (i - 1) * 2][i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}