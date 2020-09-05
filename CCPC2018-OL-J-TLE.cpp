#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <ctime>
#define maxn 100005
using namespace std;
struct ranks
{
    int x;
    int y;
    int val;
    int rkx;
    int rky;
} r[maxn];
int n, dp[maxn], tree[maxn];
vector<pair<int, int>> v1[maxn];
inline bool cmp1(const ranks &A, const ranks &B)
{
    return A.x < B.x;
}
inline bool cmp2(const ranks &A, const ranks &B)
{
    return A.y < B.y;
}
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
inline int lowbit(int x)
{
    return x & (-x);
}
inline int query(int x)
{
    int ans = 0;
    for (register int i = x; i; i -= lowbit(x))
        ans = max(ans, tree[i]);
    return ans;
}
inline void update(int x, int k)
{
    for (register int i = x; i <= n; i += lowbit(x))
        tree[i] = max(tree[i], k);
}
int main(void)
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //double start = (double)clock();

    int T;
    T = read();
    while (T--)
    {
        n = read();
        memset(tree, 0, sizeof(tree));

        for (register int i = 1; i <= n; i++)
            r[i].x = read(), r[i].y = read(), r[i].val = read();
        sort(r + 1, r + n + 1, cmp1);
        for (register int i = 1; i <= n; i++)
            r[i].x == r[i - 1].x ? r[i].rkx = r[i - 1].rkx : r[i].rkx = r[i - 1].rkx + 1;
        sort(r + 1, r + n + 1, cmp2);
        for (register int i = 1; i <= n; i++)
            r[i].y == r[i - 1].y ? r[i].rky = r[i - 1].rky : r[i].rky = r[i - 1].rky + 1;

        for (register int i = n; i >= 1; i--)
            v1[r[i].rkx].push_back(make_pair(r[i].rky, r[i].val));

        for (register int i = 1; i <= n; i++)
        {
            dp[i] = 0;
            for (register int j = 0; j < v1[i].size(); j++)
            {
                int maxx = query(v1[i][j].first - 1);
                dp[i] = max(dp[i], maxx + v1[i][j].second);
                update(v1[i][j].first, dp[i]);
            }
        }
        int ans = 0;
        for (register int i = 1; i <= n; i++)
            ans = max(ans, dp[i]);
        printf("%d\n", ans);
    }
    //double finish = (double)clock();
    //printf("%.4fms\n", (finish - start));
    //system("pause");
    return 0;
}
