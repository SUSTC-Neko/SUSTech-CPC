#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1.5e7 + 5;
int a[maxn], num[maxn];

int main()
{
    ios::sync_with_stdio(false);

    int n, h;
    cin >> n;
    int g, m = 0, ans = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h;
        if (i == 1)
            g = h;
        else
            g = __gcd(g, h);
        num[h]++;
        if (h > m)
            m = h;
    }
    for (int i = g + 1; i <= m; i++)
    {
        if (a[i] == 0)
        {
            int cnt = 0;
            for (int j = i; j <= m; j += i)
                a[j] = 1, cnt += num[j];
            ans = min(ans, n - cnt);
        }
    }
    if (ans == n)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}