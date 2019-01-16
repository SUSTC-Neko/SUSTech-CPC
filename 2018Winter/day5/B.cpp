#include <cstring> //用c++的输入就过了。
#include <cstdio>
#include <iostream>
using namespace std;

#define ll long long

struct matrix
{
    ll mat[2][2];
};

matrix operator*(matrix a, matrix b)
{
    matrix c;
    memset(c.mat, 0, sizeof(c.mat));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (a.mat[i][j] == 0)
                continue;
            for (int k = 0; k < 2; k++)
            {
                if (b.mat[j][k] == 0)
                    continue;
                c.mat[i][k] += a.mat[i][j] * b.mat[j][k];
            }
        }
    }
    return c;
}

matrix operator^(matrix a, ll b)
{
    matrix res;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            res.mat[i][j] = (i == j);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}

int main()
{
    ll p, q, n;
    while (cin >> p >> q >> n)
    {
        if (n == 0)
            printf("2\n");
        else if (n == 1)
            printf("%lld\n", p);
        else if (n == 2)
            printf("%lld\n", p * p - 2 * q);
        else
        {
            matrix ans;
            ans.mat[0][0] = p;
            ans.mat[0][1] = 1;
            ans.mat[1][0] = -q;
            ans.mat[1][1] = 0;

            ans = ans ^ (n - 1);
            ll ant = p * ans.mat[0][0] + 2 * ans.mat[1][0];
            printf("%lld\n", ant);
        }
    }
    return 0;
}