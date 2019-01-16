#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mk make_pair
#define f first
#define s second
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 255;
struct node
{
    int u, v;
    ll w;
};
node e[MAXN << 1];
pair<int, ll> p[MAXN];
bool cmp(pair<int, ll> p1, pair<int, ll> p2)
{
    return p1.s < p2.s;
}
bool cmp2(node e1, node e2)
{
    return e1.w < e2.w;
}
int pre[MAXN];
void init(int n)
{
    for (int i = 0; i <= n; ++i)
        pre[i] = i;
}
int Find(int x) //并查集
{
    int t = x;
    while (pre[t] != t)
        t = pre[t];
    while (x != pre[x])
    {
        int tep = pre[x];
        pre[x] = t;
        x = tep;
    }
    return t;
}
bool Mix(int x, int y)
{
    int Fx = Find(x);
    int Fy = Find(y);
    if (Fx != Fy)
    {
        pre[Fy] = Fx;
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    ll v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v;
        p[i - 1] = mk(i, v);
    }
    int len = 0;
    while (m--)
    {
        cin >> e[len].v >> e[len].u;
        cin >> e[len++].w;
    }
    sort(p, p + n, cmp);
    for (int i = 1; i < n; ++i) //加入n-1条边
    {
        e[len].u = p[0].f;
        e[len].v = p[i].f;
        e[len++].w = p[0].s + p[i].s;
    }
    sort(e, e + len, cmp2);
    init(n);
    int num = n - 1;
    ll ans = 0;
    for (int i = 0; i < len; ++i) //Kruskal算法
    {
        if (Mix(e[i].v, e[i].u))
        {
            ans += e[i].w;
            num--;
        }
    }
    cout << ans;
    return 0;
}
