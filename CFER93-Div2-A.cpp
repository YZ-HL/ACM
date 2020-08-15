#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, a[maxn];
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int a1 = a[1], a2 = a[2], a3 = a[n];
        if(a1+a2 <= a3)
            printf("1 2 %d\n", n);
        else
            printf("-1\n");
    }
    system("pause");
    return 0;
}