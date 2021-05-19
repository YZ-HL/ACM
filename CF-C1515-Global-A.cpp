#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, x, w[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        int sum = 0;
        scanf("%d %d", &n, &x);
        for(int i = 1; i <= n; i++)
            scanf("%d", &w[i]), sum += w[i];
        if(sum == x)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        sort(w + 1, w + n + 1);
        int nowsum = 0;
        int vis[105];
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            if(vis[i])    continue;
            if(w[i] + nowsum == x)
            {
                for(int j = n; j >= 1; j--)
                {
                    if(vis[j])    continue;
                    vis[j] = 1;
                    printf("%d ", w[j]);
                    nowsum += w[j];
                    break;
                }
                i--;
                continue;
            }
            vis[i] = 1;
            printf("%d ", w[i]);
            nowsum += w[i];
        }
        putchar('\n');
    }
    return 0;
}
