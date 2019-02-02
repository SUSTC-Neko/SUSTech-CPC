#include <bits/stdc++.h>
using namespace std;

int pixel[256];
int main()
{
    int n, k;
    cin >> n >> k;
    memset(pixel, -1, sizeof pixel);
    while (n--)
    {
        int x;
        cin >> x;
        if (pixel[x] == -1)
        {
            for (int i = max(0, x - k + 1); i <= x; i++)
            {
                if (pixel[i] == -1 || pixel[i] == i)
                {
                    for (int j = i; j <= x; j++)
                        pixel[j] = i;
                    break;
                }
            }
        }
        cout << pixel[x] << " ";
    }
    return 0;
}