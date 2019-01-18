#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 300005;
const ll mod = 100000007;

ll fac[maxn], Inv[maxn];
ll pow_mod(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
ll C(int n, int m)
{
    return fac[n] * Inv[n - m] % mod * Inv[m] % mod;
}

void init()
{
    fac[0] = Inv[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * (ll)i % mod;
        Inv[i] = pow_mod(fac[i], (ll)(mod - 2));
    }
}

int main()
{
    init();
    int m, n, p, q;
    while (~scanf("%d%d%d%d", &m, &n, &p, &q))
    {
        ll ans = 0;
        ans = (C(m + n, n) * C(m - p + q, q) % mod - C(m + q, q) * C(m - p + n, n) % mod + mod) % mod;
        printf("%lld\n", ans);
    }
}