#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 150005

struct number
{
    ll num;
    int id;
    bool operator<(const number &x) const
    {
        if (x.num == num)
            return x.id < id;
        return x.num < num;
    }
} q[maxn];

ll ans[maxn];

int main()
{
    memset(ans, -1, sizeof(ans));
    int n;
    cin >> n;
    priority_queue<number> pq;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i].num;
        q[i].id = i;
        pq.push(q[i]);
    }
    int cnt = 0;
    while (pq.size() > 1)
    {
        number num1 = pq.top();
        pq.pop();
        number num2 = pq.top();
        pq.pop();
        if (num1.num != num2.num)
        {
            ans[num1.id] = num1.num;
            pq.push(num2);
            cnt++;
            continue;
        }
        else
        {
            num2.num = num2.num * 2;
            pq.push(num2);
        }
    }
    while (!pq.empty())
    {
        number num3 = pq.top();
        pq.pop();
        ans[num3.id] = num3.num;
        cnt++;
    }
    cout << cnt << endl;
    for (int i = 0; i <= n; i++)
    {
        if (ans[i] > 0)
            cout << ans[i] << " ";
    }
    return 0;
}