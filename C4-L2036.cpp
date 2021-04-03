#include <bits/stdc++.h>
#define maxn 205
using namespace std;
int n, m, k, minn = (1 << 30), vis[maxn];
vector<int> ck[maxn];
int kcost[maxn], board[maxn][maxn];
int check(int ki, int now, int cnt, int val){
    if(cnt == n)    return val;
    if(cnt >= ck[ki].size())    return -1;
    if(vis[now])    return -1;
    vis[now] = 1;
    if(board[now][ck[ki][cnt]] != -1)
        return check(ki, ck[ki][cnt], cnt + 1, val + board[now][ck[ki][cnt]]);
    else
        return -1;
}
int main(void)
{
    memset(board, -1, sizeof(board));
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if(board[u][v] == -1 || board[u][v] > w)
            board[u][v] = board[v][u] = w;
    }
    scanf("%d", &k);
    for(int i = 1; i <= k; i++)
    {
        int nn, tmp;
        scanf("%d", &nn);
        for(int j = 1; j <= nn; j++)
        {
            scanf("%d", &tmp);
            ck[i].push_back(tmp);
        }
    }
    for(int i = 1; i <= k; i++)
    {
        int Vn = ck[i][ck[i].size() - 1], V1 = ck[i][0];
        if(ck[i].size() == n && board[Vn][0] != -1 && board[0][V1] != -1)
        {
            memset(vis, 0, sizeof(vis));
            int cost = check(i, 0, 0, 0);
            if(cost == -1)    continue;
            cost += board[Vn][0];
            minn = min(minn, cost);
            kcost[i] = cost;
        }
    }
    int ans = -1, num = 0;
    for(int i = 1; i <= k; i++)
    {
        if(kcost[i] == minn)   
        {
            if(ans == -1)   ans = i;
            num++;
        }  
        else if(kcost[i])   num++;
    }
    printf("%d\n", num);
    printf("%d %d\n", ans, minn);
    return 0;
}
