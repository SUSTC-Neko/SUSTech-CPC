#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 1;

int ans[11], ans2[11];

int main()
{
    int t, n;
    scanf("%d", &t);
    // 1 < n < 11
    ans[0] = -1;
    ans[1] = -1;
    ans[2] = 1;
    ans[3] = 1;
    ans[4] = 1;
    ans[5] = 1;
    ans[6] = 2;
    ans[7] = 3;
    ans[8] = 2;
    ans[9] = 2;
    ans[10] = 2;
    // n >= 11
    ans2[0] = 0;
    ans2[1] = 1;
    ans2[2] = 1;
    ans2[3] = 1;
    ans2[4] = 1;
    ans2[5] = 1;
    ans2[6] = 2;
    ans2[7] = 2;
    ans2[8] = 2;
    ans2[9] = 2;
    ans2[10] = 2;
    while (t--)
    {
        scanf("%d", &n);
        if (n < 11)
            printf("%d\n", ans[n]);
        else
            printf("%d\n", 2 * (n / 11) + ans2[n % 11]);
    }
}