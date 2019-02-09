#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 55003;
const int M = 320001;
int cnt;
int Head[N];
int Next[M];
int W[M];
int V[M];
int Depth[N];
int cur[N];
int s, t, n, m;
const int inf = 0x3f3f3f3f;

void init()
{
    cnt = -1;
    memset(Head, -1, sizeof(Head));
    memset(Next, -1, sizeof(Next));
}

void _Add(int u, int v, int w)
{
    cnt++;
    Next[cnt] = Head[u];
    Head[u] = cnt;
    V[cnt] = v;
    W[cnt] = w;
}

void Add_Edge(int u, int v, int w)
{
    _Add(u, v, w);
    _Add(v, u, 0);
}

int dfs(int u, int flow)
{
    if (u == t)
        return flow;
    for (int &i = cur[u]; i != -1; i = Next[i])
        if ((Depth[V[i]] == Depth[u] + 1) && (W[i] != 0))
        {
            int di = dfs(V[i], min(flow, W[i]));
            if (di > 0)
            {
                W[i] -= di;
                W[i ^ 1] += di;
                return di;
            }
        }
    return 0;
}

int bfs()
{
    queue<int> Q;
    while (!Q.empty())
        Q.pop();
    memset(Depth, 0, sizeof(Depth));
    Depth[s] = 1;
    Q.push(s);
    do
    {
        int u = Q.front();
        Q.pop();
        for (int i = Head[u]; i != -1; i = Next[i])
        {
            if ((Depth[V[i]] == 0) && (W[i] > 0))
            {
                Depth[V[i]] = Depth[u] + 1;
                Q.push(V[i]);
            }
        }
    } while (!Q.empty());
    if (Depth[t] > 0)
        return 1;
    return 0;
}

int Dinic()
{
    int Ans = 0;
    while (bfs())
    {
        for (int i = s; i <= t; i++)
            cur[i] = Head[i];
        while (int d = dfs(s, inf))
            Ans += d;
    }
    return Ans;
}

int main()
{
    cin >> n >> m;
    init();
    int ans = 0;
    s = 0;
    t = n + m + 1;

    for (int i = 1; i <= n; i++)
    {
        int pi;
        cin >> pi;
        // getchar();
        Add_Edge(s, i, pi);
    }
    for (int i = 1; i <= m; i++)
    {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        ans += ci;
        Add_Edge(n + i, t, ci);
        Add_Edge(ai, n + i, inf);
        Add_Edge(bi, n + i, inf);
    }
    int ans1 = Dinic();
    cout << (ans - ans1);
    return 0;
}