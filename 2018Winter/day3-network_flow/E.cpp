#include <bits/stdc++.h>
using namespace std;
int T, N, tmp;
int stone[51];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &stone[i]);
        sort(stone, stone + N);
        if (stone[N - 1] == 1)
        {
            if (N & 1)
                printf("%s\n", "Brother");
            else
                printf("%s\n", "John");
            continue;
        }
        tmp = stone[0];
        for (int i = 1; i < N; ++i)
            tmp ^= stone[i];
        if (tmp == 0)
            printf("%s\n", "Brother");
        else
            printf("%s\n", "John");
    }
    return 0;
}