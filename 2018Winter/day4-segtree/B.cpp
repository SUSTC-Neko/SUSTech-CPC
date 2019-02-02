#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stack>
using namespace std;

const int maxn = 50000 + 10;

int n, m;

struct node
{
    int l, r;
    int lmax, rmax, mmax;
} segTree[maxn << 2];

void build(int root, int l, int r)
{
    segTree[root].l = l;
    segTree[root].r = r;
    segTree[root].lmax = segTree[root].rmax = segTree[root].mmax = r - l + 1;
    if (l != r)
    {
        int mid = (l + r) >> 1;
        build(root * 2, l, mid);
        build(root * 2 + 1, mid + 1, r);
    }
}

void update(int root, int node, int x)
{
    if (segTree[root].l == segTree[root].r)
    {
        if (x == 1)
            segTree[root].lmax = segTree[root].rmax = segTree[root].mmax = 1;
        else
            segTree[root].lmax = segTree[root].rmax = segTree[root].mmax = 0;
        return;
    }
    int mid = (segTree[root].l + segTree[root].r) >> 1;
    if (node <= mid)
        update(2 * root, node, x);
    else
        update(2 * root + 1, node, x);
    segTree[root].lmax = segTree[2 * root].lmax;
    segTree[root].rmax = segTree[2 * root + 1].rmax;
    segTree[root].mmax = max(max(segTree[2 * root].mmax, segTree[2 * root + 1].mmax), segTree[2 * root].rmax + segTree[2 * root + 1].lmax);
    if (segTree[2 * root].lmax == segTree[2 * root].r - segTree[2 * root].l + 1)
        segTree[root].lmax += segTree[2 * root + 1].lmax;
    if (segTree[2 * root + 1].rmax == segTree[2 * root + 1].r - segTree[2 * root + 1].l + 1)
        segTree[root].rmax += segTree[2 * root].rmax;
}

int query(int root, int node)
{
    if (segTree[root].l == segTree[root].r || segTree[root].mmax == 0 || segTree[root].mmax == segTree[root].r - segTree[root].l + 1)
        return segTree[root].mmax;
    int mid = (segTree[root].l + segTree[root].r) >> 1;
    if (node <= mid)
    {
        if (node >= segTree[2 * root].r - segTree[2 * root].rmax + 1)
            return query(2 * root, node) + query(2 * root + 1, mid + 1);
        else
            return query(2 * root, node);
    }
    else
    {
        if (node <= segTree[2 * root + 1].l + segTree[2 * root + 1].lmax - 1)
            return query(2 * root + 1, node) + query(2 * root, mid);
        else
            return query(2 * root + 1, node);
    }
}

int main()
{
    int root, j, x;
    char ch[2];
    stack<int> s;
    while (~scanf("%d%d", &n, &m))
    {

        build(1, 1, n);
        while (m--)
        {
            scanf("%s", ch);
            switch (ch[0])
            {
            case 'D':
                scanf("%d", &x);
                s.push(x);
                update(1, x, 0);
                break;
            case 'R':
                if (x > 0)
                {
                    x = s.top();
                    s.pop();
                    update(1, x, 1);
                }
                break;
            case 'Q':
                scanf("%d", &x);
                printf("%d\n", query(1, x));
                break;
            }
        }
    }

    return 0;
}
