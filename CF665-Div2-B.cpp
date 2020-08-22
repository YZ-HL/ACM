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
    while(t--)
    {
        int x1, y1, z1, x2, y2, z2, ans = 0;
        scanf("%d %d %d", &x1, &y1, &z1);
        scanf("%d %d %d", &x2, &y2, &z2);
        int minn = min(z1, y2);
        ans += minn * 2;
        z1 -= minn;
        y2 -= minn;
        if(y1 <= x2+y2)
        {
            printf("%d\n", ans);
            continue;
        }
        else
        {
            y1 -= x2 + y2;
            x2 = 0;
            y2 = 0;
        }
        if(z2 <= x1+z1)
        {
            printf("%d\n", ans);
            continue;
        }
        else
        {
            z2 -= x1 + z1;
            x1 = 0;
            z1 = 0;
        }
        printf("%d\n", ans - y1 * z2 * 2);
    }
    system("pause");
    return 0;
}
