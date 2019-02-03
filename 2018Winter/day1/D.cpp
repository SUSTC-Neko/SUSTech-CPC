#include <bits\stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    int n, val;
    ll a, b, c, d;
    a = b = c = d = 0;
    string str;
    cin >> n >> str;
    for (int i = 0; i < str.length(); i++)
    {
        cin >> val;
        switch (str[i])
        {
        case 'h':
            a += val;
            break;
        case 'a':
            b = min(a, b + val);
            break;
        case 'r':
            c = min(b, c + val);
            break;
        case 'd':
            d = min(c, d + val);
            break;
        }
    }
    cout << d << endl;
    return 0;
}