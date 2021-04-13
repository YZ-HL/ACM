#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int a, b, x, y;
int main(void)
{
    scanf("%d %d %d %d", &a, &b, &x, &y);
    if(a == b)
        printf("%d\n", x);
    else if(a == b + 1)
        printf("%d\n", x);
    else if(a < b)
    {
        int minn = min(x * 2, y);
        printf("%d\n", abs(b - a) * minn + x);
    }
    else if(a > b)
    {
        int minn = min(x * 2, y), minn2 = min(3 * x, y);
        printf("%d\n", 2 * x < y ? (a - b - 1) * 2 * x + x : (a - b - 1) * y + x);
        /*
        if(abs(b - a) % 2 == 0)
            printf("%d\n", minn2 * (abs(b - a)));
        else
        */

    }
    return 0;
}
