#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int dp[1001][1001], visit[1001][1001], a[1001], sum[1001];

int dfs(int l, int r)
{
    if (visit[l][r])
        return dp[l][r];
    else if (l == r)
        return dp[l][r];
    visit[l][r] = 1;
    int lnext = dfs(l + 1, r);
    int rnext = dfs(l, r - 1);
    int total = sum[r] - sum[l - 1];
    dp[l][r] = max(total - lnext, total - rnext);
    return dp[l][r];
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        memset(visit, 0, sizeof(dp));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            visit[i][i] = 1;
            dp[i][i] = a[i];
        }
        int ans = dfs(1, n);
        printf("%d\n", 2 * ans - sum[n]);
    }
    return 0;
}