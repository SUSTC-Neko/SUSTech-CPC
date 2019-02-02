#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int main()
{
    int t, n;
    double m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int cnt = 0;
        int score = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> score;
            if (score >= 50)
                cnt++;
        }
        if (cnt >= ceil(n * m))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}