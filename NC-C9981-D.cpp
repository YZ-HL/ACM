#include <bits/stdc++.h>
#define maxn 1005
#define int long long
#define mod 1000000007
using namespace std;
int n, k, tx, ty;
int cnt, siz[maxn * maxn], uset[maxn * maxn];
char board[maxn][maxn];
char get_char(){
    char ch = getchar();
    while(ch != '1' && ch != '0')    ch = getchar();
    return ch;
}
int calc(int x, int y){
    return x * n + y;
}
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unioon(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy)    return;
    uset[fx] = fy;
    siz[fy] += siz[fx];
}
int quickpow(int a, int b, int p){
    if(b == 0)    return 1;
    int tmp = quickpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)    tmp = (tmp * a) % p;
    return tmp;
}
int inv(int x){
    return quickpow(x, mod - 2, mod);
}
int cnum, vis[maxn][maxn];
int fx[] = {0, 1, -1, 0, 0};
int fy[] = {0, 0, 0, 1, -1};
bool dfs(int x, int y){
    if(vis[x][y])    return false;
    if(board[x][y] == '0')    return false;
    if(x < 1 || y < 1 || x > n || y > n)    return false;
    
    cnum++; vis[x][y] = 1;
    for(int i = 1; i <= 4; i++)
    {
        int nx = x + fx[i], ny = y + fy[i];
        if(dfs(nx, ny))
            unioon(calc(x, y), calc(nx, ny));
    }
    return true;
}
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            board[i][j] = get_char();
            uset[calc(i, j)] = calc(i, j);
        }
    int ans = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(!vis[i][j] && board[i][j] == '1')
            {
                cnum = 0;
                dfs(i, j);
                siz[find(calc(i, j))] = cnum;
                ans = (ans * siz[find(calc(i, j))]) % mod;
                cnt++;
            }
        }    
    for(int i = 1; i <= cnt; i++)    ans = (ans * i) % mod;
    scanf("%lld", &k);
    for(int i = 1; i <= k; i++)
    {
        scanf("%lld %lld", &tx, &ty);
        tx++; ty++;
        if(board[tx][ty] == '1')
        {
            printf("%lld\n", ans);
            continue;
        }
        cnt++;
        board[tx][ty] = '1';
        siz[calc(tx, ty)] = 1;
        ans = (ans * cnt) % mod;
        for(int k = 1; k <= 4; k++)
        {
            int nx = tx + fx[k];
            int ny = ty + fy[k];
            if(board[nx][ny] != '1')    continue;
            int f1 = find(calc(tx, ty));
            int f2 = find(calc(nx, ny));
            if(f1 == f2)    continue;
            ans = (ans * inv(cnt)) % mod;
            ans = (ans * inv(siz[f1])) % mod;
            ans = (ans * inv(siz[f2])) % mod;
            ans = (ans * (siz[f1] + siz[f2])) % mod;
            //printf("%lld %lld %lld %lld\n", siz[f1], siz[f2], cnt, inv(cnt));
            cnt--;
            unioon(f1, f2);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
