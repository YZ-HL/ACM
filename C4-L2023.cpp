#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int v, e, k, n, G[maxn][maxn], C[maxn];
int used[maxn], cnt = 0;
bool check(){
    for(int i = 1; i <= v; i++)
        for(int j = 1; j <= v; j++)
            if(G[i][j] && C[i] == C[j])
                return false;
    return true;
}
int main(void)
{
    scanf("%d %d %d", &v, &e, &k);
    for(int i = 1; i <= e; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        cnt = 0;
        memset(used, 0, sizeof(used));

        for(int j = 1; j <= v; j++)
        {
            scanf("%d", &C[j]);
            if(!used[C[j]])
            {
                used[C[j]] = 1;
                cnt++;
            }
        }
        printf(check() && cnt == k ? "Yes\n" : "No\n");
    }
    return 0;
}