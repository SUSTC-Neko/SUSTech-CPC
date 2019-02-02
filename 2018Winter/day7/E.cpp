#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int b = 0, l = 0, k = 0;
        cin >> n;
        string str;
        while (n--)
        {
            cin >> str;
            if (str[0] == 'b')
            {
                b++;
            }
            else if (str[0] == 'k')
            {
                k++;
            }
            else
            {
                l++;
            }
        }
        int b1 = b / 2;
        int ans = min(min(l, k), b1);
        cout << ans << endl;
    }
    return 0;
}
