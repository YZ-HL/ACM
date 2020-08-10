#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, a[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if(a[i] > 1)    break;
            if(i < n)       flag ^= 1;
            //printf("DEBUG: %d %d\n", flag, a[i]);
        }
        printf(flag ? "First" : "Second");
        putchar('\n');
    }
    system("pause");
    return 0;
}