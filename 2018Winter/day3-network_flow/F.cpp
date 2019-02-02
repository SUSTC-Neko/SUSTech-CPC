#include <bits/stdc++.h>
using namespace std;
stack<char> sta;
const int mx = 500001;
int suml[mx], sumr[mx];
string str;
int ans = 0;
int n, num0 = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        while (!sta.empty())
            sta.pop();
        sta.push(str[0]);
        for (int j = 1; str[j] != '\0'; j++)
        {
            if (!sta.empty())
            {
                if (sta.top() == '(' && str[j] == ')')
                    sta.pop();
                else
                    sta.push(str[j]);
            }
            else
                sta.push(str[j]);
        }
        int l = 0, r = 0;
        while (!sta.empty())
        {
            char ch = sta.top();
            sta.pop();
            if (ch == '(')
                l++;
            else
                r++;
        }
        if (l != 0 && r != 0)
            continue;
        else if (l == 0 && r == 0)
            num0++;
        else if (l != 0)
            suml[l]++;
        else if (r != 0)
            sumr[r]++;
    }
    for (int i = 1; i <= mx; i++)
    {
        if (suml[i] > sumr[i])
            ans += sumr[i];
        else
            ans += suml[i];
    }
    ans += (num0 / 2);
    printf("%d\n", ans);
    return 0;
}
