#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m, k, a[maxn], se[maxn];
int s[maxn], sg[maxn];
void SG(){
    memset(sg, 0, sizeof(sg));
    for(int i = 1; i <= 1000; i++)
    {
        memset(s, 0, sizeof(s));
        for(int j = 1; se[j] <= i && j <= se[0]; j++)    
        {
            s[sg[i-se[j]]] = 1;
            int tot = i - se[j];
            for(int k = 1; k <= tot - 1; k++)
                s[sg[k]^sg[tot-k]] = 1;
        }
        for(int j = 0; j <= 1000; j++)
        {
            if(!s[j])
            {
                sg[i] = j;
                break;
            }
        }
    }
}
int main(void)
{
    while(~scanf("%d", &n))
    {
        se[0] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        for(int i = 1; i <= n; i++)
            if(a[i] != a[i-1])  se[++se[0]] = a[i];
        SG();
        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d", &k);
            printf(sg[k] ? "1" : "2");
            putchar('\n');
        }
    }
    return 0;
}