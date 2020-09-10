#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int a[maxn];
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = n; i >= 1; i--)
            printf("%d ", a[i]);
        putchar('\n');
    }
    system("pause");
    return 0;
}
