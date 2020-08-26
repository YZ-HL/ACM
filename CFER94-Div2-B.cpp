#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int p, f, cnts, cntw, s, w;
        scanf("%d %d", &p, &f);
        scanf("%d %d", &cnts, &cntw);
        scanf("%d %d", &s, &w);

        int ans = 0;
        if (s > w)
        {
            for (int i = 0; i <= cntw && i * w <= p; i++)
            {
                int tmp1 = min(cnts, (p - (i * w)) / s);
                int tmp2 = min(cntw - i, f / w);
                int tmp3 = min(cnts - tmp1, (f - tmp2 * w) / s);
                ans = max(ans, tmp1 + tmp2 + tmp3 + i);
            }
        }
        else
        {
            for (int i = 0; i <= cnts && i * s <= p; i++)
            {
                int tmp1 = min(cntw, (p - (i * s)) / w);
                int tmp2 = min(cnts - i, f / s);
                int tmp3 = min(cntw - tmp1, (f - tmp2 * s) / w);
                ans = max(ans, tmp1 + tmp2 + tmp3 + i);
            }
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}
