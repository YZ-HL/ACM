#include <bits/stdc++.h>
using namespace std;
int m, n, l, t;
const int maxn = 1286 * 128 * 60 * 5;
int uset[maxn], sum[maxn], board[13000 * 130 * 65];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unioon(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)    return;
    uset[fx] = fy;
}
int calc(int now_m, int now_n, int now_l){
    return (now_l - 1) * m * n + (now_m - 1) * n + now_n;
}
int main(void)
{
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for(int i = 1; i <= m * n * l; i++)    uset[i] = i;
    for(int i = 1; i <= l; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                scanf("%d", &board[calc(j, k, i)]);
            }
        }
    }
    for(int i = 1; i <= l; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                if(board[calc(j, k, i)] == 0)    continue;
                int nowpos = calc(j, k, i);
                
                if(j > 1 && board[calc(j - 1, k, i)] == 1)
                    unioon(nowpos, calc(j - 1, k, i));
                
                if(j < m && board[calc(j + 1, k, i)] == 1)
                    unioon(nowpos, calc(j + 1, k, i));
                
                if(k > 1 && board[calc(j, k - 1, i)] == 1)
                    unioon(nowpos, calc(j, k - 1, i));
                
                if(k < n && board[calc(j, k + 1, i)] == 1)
                    unioon(nowpos, calc(j, k + 1, i));
                
                if(i > 1 && board[calc(j, k, i - 1)] == 1)
                    unioon(nowpos, calc(j, k, i - 1));
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m * n * l; i++)    sum[find(i)]++;
    for(int i = 1; i <= m * n * l; i++)
    {
        if(find(i) == i && sum[find(i)] >= t && board[i] == 1)
        {
            ans += sum[find(i)];
        }
    }
    printf("%d\n", ans);
    return 0;
}
