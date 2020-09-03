#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, a[maxn], sum, maxx;
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        sum = 0;
        maxx = -1;
    
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]), maxx = max(maxx, a[i]), sum += a[i];
        if(maxx*2 > sum)
            printf("T\n");
        else
            printf(sum & 1 ? "T\n" : "HL\n");
    }
    system("pause");
    return 0;
}
