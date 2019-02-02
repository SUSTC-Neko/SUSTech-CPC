#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ld e, f;
        e = b * log(a);
        f = d * log(c);
        if (e > f)
            cout << ">" << endl;
        else
            cout << "<" << endl;
    }
    return 0;
}
