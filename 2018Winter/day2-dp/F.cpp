#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
int a[20];
long long dp[20][2];
long long dfs(int pos, int pre, int sta, bool limit)
{
    if (pos == -1)
        return 1;
    if (!limit && dp[pos][sta] != -1)
        return dp[pos][sta];
    int up = limit ? a[pos] : 9;
    long long tmp = 0;
    for (int i = 0; i <= up; i++)
    {
        if (pre == 4 && i == 9)
            continue;
        tmp += dfs(pos - 1, i, i == 4, limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][sta] = tmp;
    return tmp;
}
long long solve(long long x)
{
    int pos = 0;
    while (x)
    {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, -1, 0, true);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        long long num;
        scanf("%lld", &num);
        memset(dp, -1, sizeof dp);
        printf("%lld\n", num - solve(num) + 1);
    }
    return 0;
}
