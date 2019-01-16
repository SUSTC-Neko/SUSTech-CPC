#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll dp[20][1024], dp2[20][1024], res[20][1024], a[20];
ll l, r;
int k;

ll dfs(int pos, int state, int limit, int lead)
{
    if (pos == 0 && state == 1 && lead)
        return 1;
    if (state == 0 && pos != 0)
        return 0;
    if (pos == 0)
    {
        if (state == 0)
            return 1;
        else
            return 0;
    }
    if (!limit && !lead && dp[pos][state] != -1)
    {
        res[pos][state] = dp2[pos][state];
        return dp[pos][state];
    }
    ll ans = 0;
    int down = 0, up = limit ? a[pos] : 9;
    if (lead)
    {
        down = 1;
        ans = (ans + dfs(pos - 1, state, 0, 1)) % mod;
        res[pos][state] = res[pos - 1][state];
    }
    else
    {
        res[pos][state] = 0;
    }
    for (int i = down; i <= up; i++)
    {
        if (state & (1 << i))
        {
            ll t1 = dfs(pos - 1, state, limit && i == a[pos], lead && i == 0);
            ll t2 = dfs(pos - 1, state ^ (1 << i), limit && i == a[pos], lead && i == 0);
            ans = (ans + t1 + t2) % mod;
            ll t = (t1 + t2) % mod * i % mod;
            for (int j = 1; j <= pos - 1; j++)
                t = t * 10LL % mod;
            res[pos][state] = (res[pos][state] + res[pos - 1][state] + res[pos - 1][state ^ (1 << i)] + t) % mod;
        }
    }
    if (!limit && !lead)
    {
        dp[pos][state] = ans;
        dp2[pos][state] = res[pos][state];
    }
    return ans;
}

ll solve(ll x)
{
    if (x == 0)
        return 0;
    int pos = 0;
    while (x)
    {
        a[++pos] = x % 10;
        x /= 10;
    }
    memset(dp, -1, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    memset(res, 0, sizeof(res));
    ll ans = 0;
    for (int i = 1; i < (1 << 10); i++)
    {
        int t = 0;
        for (int j = 0; j < 10; j++)
            if (i & (1 << j))
                t++;
        if (t <= k)
        {
            dfs(pos, i, 1, 1);
            ans = (ans + res[pos][i]) % mod;
        }
    }
    return ans;
}

int main()
{
    scanf("%I64d%I64d%d", &l, &r, &k);
    printf("%I64d\n", (solve(r) - solve(l - 1) + mod) % mod);
    return 0;
}
