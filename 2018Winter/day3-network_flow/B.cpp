#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn = 2e5 + 10;

ll n, m, minnumindex;
ll minnum;
ll nodeval[maxn];

struct EDGE
{
    ll u, v, w;
    EDGE() {}
    // 初始化列表
    EDGE(ll u, ll v, ll w) : u(u), v(v), w(w) {}
} edge[2 * maxn];

ll parent[maxn];
ll sum;

inline void init()
{
    sum = 0;
    memset(parent, -1, sizeof(parent));
}

bool cmp(const EDGE &edge1, const EDGE &edge2)
{
    return edge1.w < edge2.w;
}

inline ll find(ll x)
{

    ll pos;

    for (pos = x; parent[pos] > 0; pos = parent[pos])
        ;

    while (pos != x)
    {
        ll tmp = parent[x];
        parent[x] = pos;
        x = tmp;
    }
    return pos;
}

inline void Union(ll u, ll v)
{

    ll tmp = parent[u] + parent[v];

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
    scanf("%d%d", &n, &m);
    minnum = __LONG_MAX__;
    minnumindex = 0;
    init();
    for (ll i = 1; i <= n; i++)
    {
        scanf("%I64d", &nodeval[i]);
        if (minnum > nodeval[i])
        {
            minnum = nodeval[i];
            minnumindex = i;
        }
    }
    for (ll i = 1; i <= n; i++)
        if (i != minnumindex)
            edge[i] = EDGE(minnumindex, i, nodeval[i] + minnum);

    for (ll i = n + 1; i <= n + m; i++)
        scanf("%I64d%I64d%I64d", &edge[i].u, &edge[i].v, &edge[i].w);

    sort(edge + 1, edge + n + m + 1, cmp);

    for (ll i = 1; i <= n + m; ++i)
    {
        ll u = find(edge[i].u), v = find(edge[i].v);
        if (u != v)
        {
            sum += edge[i].w;
            Union(u, v);
        }
    }
    printf("%I64d\n", sum);

    return 0;
}