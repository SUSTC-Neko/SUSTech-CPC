#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
char SWAP[26];
string str1, str2;
int cnt;

int main()
{
    ios::sync_with_stdio(false);

    cin >> str1 >> str2;
    memset(SWAP, '0', sizeof(SWAP));
    cnt = 0;
    bool f = false;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
        {
            if (SWAP[str1[i] - 'a'] == '0' && SWAP[str2[i] - 'a'] == '0')
            {
                SWAP[str1[i] - 'a'] = str2[i];
                SWAP[str2[i] - 'a'] = str1[i];
                cnt++;
            }
            else
            {
                if (SWAP[str1[i] - 'a'] == str2[i])
                {
                    continue;
                }
                else
                {
                    cout << -1 << endl;
                    f = true;
                    break;
                }
            }
        }
        else
        {
            if (SWAP[str1[i] - 'a'] == '0')
            {
                SWAP[str1[i] - 'a'] = str1[i];
            }
            else if (SWAP[str1[i] - 'a'] != str1[i])
            {
                cout << -1 << endl;
                f = true;
                break;
            }
        }
    }
    if (!f)
    {
        cout << cnt << endl;
        for (int i = 0; i < 26; i++)
        {
            if (SWAP[i] != '0' && SWAP[SWAP[i] - 'a'] != SWAP[i])
            {
                cout << SWAP[SWAP[i] - 'a'] << " " << SWAP[i] << endl;
                SWAP[SWAP[i] - 'a'] = '0';
                SWAP[i] = '0';
            }
        }
    }
    return 0;
}