#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    int n, ans, cnt, num;
    cin >> n;
    cnt = 0;
    ans = 0;
    while (n--)
    {
        cin >> num;
        if (num == 1 && cnt != 2)
        {
            cnt = 1;
        }
        else if (num == 0 && cnt == 1)
        {
            cnt = 2;
        }
        else if (num == 0 && cnt != 1)
        {
            cnt = 0;
        }
        else if (num == 1 && cnt == 2)
        {
            ans++;
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}