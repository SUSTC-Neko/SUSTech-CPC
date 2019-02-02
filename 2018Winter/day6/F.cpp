// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int dp[2001][2001];

int main()
{
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < 2001; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= 2000; i++)
    {
        for (int j = i; j <= 2000; j++)
        {
            dp[i][j] = i * dp[i][j - 1] + dp[i - 1][j - 1];
            dp[i][j] = dp[i][j] % 1000;
        }
    }
    int t, num, ans;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &num);
        ans = 0;
        for (int i = 1; i <= num; i++)
        {
            ans += dp[i][num];
            ans = ans % 1000;
        }
        printf("%d\n", ans);
    }
    return 0;
}