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
        int n, x, y, maxx = (1<<30), posd = -1;
        scanf("%d %d %d", &n, &x, &y);
        for(int d = 1; d <= 50; d++)
        {
            if((y - x) > (n-1)*d)    continue;
            if((y - x) % d)    continue;
            int minn = max(x%d ? x-(x/d)*d : d, y-(n-1)*d);
            if(minn + d*(n-1) < maxx)
                maxx = minn + d*(n-1), posd = d;
        }
        for(int i = 1; i <= n; i++)
            printf("%d ", maxx-posd*(i-1));
        putchar('\n');
    }
    system("pause");
    return 0;
}
