#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
vector<int> vec[MAXN];
int in[MAXN], out[MAXN], p[MAXN], time_tag;
void dfs(int u)
{
    in[u] = ++time_tag;
    p[in[u]] = u;
    for (int v = 0; v < vec[u].size(); v++)
    {
        dfs(vec[u][v]);
    }
    // for (auto &v : vec[u])
    //     dfs(v);
    out[u] = time_tag;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        vec[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    time_tag = 0;
    dfs(1);
    for (int i = 1; i <= q; i++)
    {
        int u, k;
        cin >> u >> k;
        if (out[u] - in[u] + 1 < k)
            cout << -1 << endl;
        else
            cout << p[in[u] + k - 1] << endl;
    }

    return 0;
}