// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

// ll power(int a, int n)
// {
//     ll ans = 1;
//     for (int i = 0; i < n; i++)
//     {
//         ans *= a;
//     }
//     return ans;
// }

int main()
{
    int n;
    ll ans;
    while (scanf("%d", &n) != EOF)
    {
        if (!n)
            break;
        ans = 0;
        ans += 1ll * n * n * n * n * n * n;               // 不变换，6个循环
        ans += 3ll * 2 * n * n * n + 3ll * n * n * n * n; // 3个面中心(90（3），180（4），270（3）)
        ans += 4ll * 2 * n * n;                           // 角中心，4对顶点，120，240
        ans += 6ll * n * n * n;                           // 6对边中心
        ans /= 24ll;
        printf("%lld\n", ans);
    }
    return 0;
}