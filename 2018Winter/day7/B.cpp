#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 1;

int a[2][maxn];
map<int, int> m;

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        m.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &a[0][i], &a[1][i]);
        for (int i = 1; i <= n; i++)
            m[a[0][i]]++;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans += m[a[1][i]];
        printf("%lld\n", ans);
    }
}