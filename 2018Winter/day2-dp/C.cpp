#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Node
{
    int start;
    int end;
    int efficitive;
} A[1000];

int dp[1000];

bool cmp(Node a, Node b)
{
    return a.start < b.start;
}

int N, M, R, i, j;

int main()
{
    scanf("%d%d%d", &N, &M, &R);
    for (i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &A[i].start, &A[i].end, &A[i].efficitive);
        A[i].end += R;
    }
    stable_sort(A, A + M, cmp);
    int count;
    count = dp[0] = A[0].efficitive;
    for (i = 1; i < M; ++i)
    {
        dp[i] = A[i].efficitive;
        for (j = i - 1; j >= 0; --j)
        {
            if (A[i].start - A[j].end >= 0)
            {
                dp[i] = max(dp[i], dp[j] + A[i].efficitive);
            }
        }
        count = max(count, dp[i]);
    }
    printf("%d\n", count);
    return 0;
}