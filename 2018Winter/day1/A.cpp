#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;

struct node
{
    int princess1, princess2, va;
} princes[maxn];

int n, m;
int F[maxn];
bool P[maxn];

int Find(int x)
{
    if (x != F[x])
        F[x] = Find(F[x]);
    return F[x];
}

int cmp(node &a, node &b)
{
    return a.va > b.va;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        F[i] = i;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &princes[i].princess1, &princes[i].princess2, &princes[i].va);
    sort(princes + 1, princes + m + 1, cmp);

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int x = Find(princes[i].princess1);
        int y = Find(princes[i].princess2);
        if (x != y)
        {
            if (P[x] && P[y])
                continue;
            P[x] = P[x] | P[y];
            F[y] = x;
            ans += princes[i].va;
        }
        else if (!P[x])
        {
            ans += princes[i].va;
            P[x] = 1;
        }
    }
    cout << ans << endl;
}