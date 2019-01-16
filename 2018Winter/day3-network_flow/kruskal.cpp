#include <bits/stdc++.h>
using namespace std;

const int maxe = 1e4 + 1;
const int maxv = 1e2 + 1;

struct EDGE
{
    int u, v, w;
    EDGE() {}
    EDGE(int u, int v, int w) : u(u), v(v), w(w) {}
} edge[maxe];

int parent[maxv];
int T, N, M, sum;

inline void init()
{
    sum = 0;
    memset(parent, -1, sizeof(parent));
}

bool cmp(const EDGE &edge1, const EDGE &edge2)
{
    return edge1.w < edge2.w;
}

inline int find(int x)
{

    int pos;

    for (pos = x; parent[pos] > 0; pos = parent[pos])
        ;

    while (pos != x)
    {
        int tmp = parent[x];
        parent[x] = pos;
        x = tmp;
    }
    return pos;
}

inline void Union(int u, int v)
{

    int tmp = parent[u] + parent[v];

    if (parent[u] > parent[v])
    {
        parent[u] = v;
        parent[v] = tmp;
    }
    else
    {
        parent[v] = u;
        parent[u] = tmp;
    }
}

int main()
{

    scanf("%d", &T);
    while (T--)
    {

        init();
        scanf("%d%d", &N, &M);

        for (int i = 1; i <= M; ++i)
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);

        sort(edge + 1, edge + M + 1, cmp);

        for (int i = 1; i <= M; ++i)
        {
            int u = find(edge[i].u), v = find(edge[i].v);
            if (u != v)
            {
                sum += edge[i].w;
                Union(u, v);
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
