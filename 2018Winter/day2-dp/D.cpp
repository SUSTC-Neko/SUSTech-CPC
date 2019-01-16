#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int pie[100001][12];

int Max2(int a, int b)
{
    return (a > b) ? a : b;
}

int Max3(int a, int b, int c)
{
    int max = (a > b) ? a : b;
    return (max > c) ? max : c;
}

int MaxNumOfPie(int max_time)
{
    int max;

    for (int i = max_time - 1; i >= 0; --i)
    {
        pie[i][0] = Max2(pie[i + 1][0], pie[i + 1][1]) + pie[i][0];
        for (int j = 1; j < 10; ++j)
        {
            pie[i][j] = Max3(pie[i + 1][j - 1], pie[i + 1][j], pie[i + 1][j + 1]) + pie[i][j];
        }
        pie[i][10] = Max2(pie[i + 1][10], pie[i + 1][9]) + pie[i][10];
    }
    return pie[0][5];
}

int main()
{
    int n, time, location, max_time;

    while (scanf("%d", &n) != EOF && n != 0)
    {
        memset(pie, 0, sizeof(pie));
        max_time = -1;
        for (int k = 1; k <= n; ++k)
        {
            scanf("%d%d", &location, &time);
            ++pie[time][location];
            if (max_time < time)
                max_time = time;
        }
        printf("%d\n", MaxNumOfPie(max_time));
    }
    return 0;
}
