#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m, t, ts[maxn], id[maxn];
int prio[maxn];
int main(void)
{
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 1; i <= m; i++)
        scanf("%d %d", &ts[i], &id[i]);
    for(int i = 1; i <= t; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int flag = 0;
            for(int k = 1; k <= m; k++)
            {
                if(ts[k] == i && id[k] == j)
                {
                    flag++;
                }
            }
            if(flag)            prio[j] += 2 * flag;
            else if(prio[j])    prio[j] --;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(prio[i] > 3)    
        {
            printf("%d %d\n", i, prio[i]);
            cnt++;
        }
    printf("%d\n", cnt);
    return 0;
}