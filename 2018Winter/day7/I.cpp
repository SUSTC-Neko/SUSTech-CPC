#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const int maxn = 251;

int graph[maxn][maxn];
int vis[maxn][maxn];
string str[maxn];
int cnt1[11], cnt2[11], dis[maxn];
queue<int> q;
int t, n, s, e;

void clear(queue<int> &q)
{
    queue<int> empty;
    swap(empty, q);
}

int bfs()
{
    q.push(s);
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        vis[i][s] = 1;
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == e)
            return dis[x];

        for (int i = 1; i <= n; i++)
        {
            if (graph[x][i] & !vis[x][i])
            {
                q.push(i);
                vis[x][i] = 1;
                if (dis[i] > dis[x] + 1)
                {
                    dis[i] = dis[x] + 1;
                }
                // cout << x << "->" << i << ":" << dis[i] << endl;
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(graph, 0, sizeof(graph));
        memset(vis, 0, sizeof(vis));
        memset(dis, INF, sizeof(dis));
        scanf("%d%d%d", &n, &s, &e);
        for (int i = 1; i <= n; i++)
            cin >> str[i];

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int cnt = 0;
                memset(cnt1, 0, sizeof(cnt1));
                memset(cnt2, 0, sizeof(cnt2));
                for (int k = 0; k < 20; k++)
                {
                    cnt1[str[i][k] - '0']++;
                    cnt2[str[j][k] - '0']++;
                }
                for (int k = 0; k < 10; k++)
                    cnt += min(cnt1[k], cnt2[k]);
                if (cnt == 17)
                    graph[i][j] = 1;
            }
        }
        clear(q);
        printf("%d\n", bfs());
    }
}