#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 20;
ld cp[maxn];

int main()
{
    int n, num;
    scanf("%d", &n);
    memset(cp, 0, sizeof(cp));
    cp[0] = -1;
    cp[1] = 0;
    cp[2] = 1;
    for (int i = 3; i <= maxn; i++)
    {
        cp[i] = (i - 1) * (cp[i - 2] + cp[i - 1]);
    }
    while (n--)
    {
        scanf("%d", &num);
        ld total = 1;
        for (int i = 1; i <= num; i++)
        {
            total *= i;
        }
        double ans = 100.0 * cp[num] / total;
        printf("%.2f%%\n", ans);
    }
    return 0;
}