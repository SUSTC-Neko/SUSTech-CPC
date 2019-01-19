#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;
ll b[maxn];

ll solve(ll x)
{
    int num = 0;
    while (x != 1)
    {
        if (x % 2 == 0)
            x /= 2;
        else
            x--;
        num++;
    }
    return num;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(b, 0, sizeof(b));
        int n, q, l, r;
        scanf("%d%d", &n, &q);
        ll x;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &x);
            b[i] = b[i - 1] + solve(x);
        }
        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d", &l, &r);
            printf("%I64d\n", b[r] - b[l - 1]);
        }
    }
    return 0;
}
