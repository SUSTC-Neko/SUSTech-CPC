#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int t, n, i, x, s;
    bool f;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        f = 1;
        s = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            s ^= x;
            if (x != 1)
            {
                f = 0;
            }
        }
        printf("%s\n", s ^ f ? "John" : "Brother");
    }
    return 0;
}