#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int y, x, ans;
        scanf("%d%d", &y, &x);
        ans = y * 100 * 1.0 / (100 + x);
        printf("%d\n", ans);
    }
    return 0;
}
