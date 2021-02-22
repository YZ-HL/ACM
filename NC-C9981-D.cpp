#include <bits/stdc++.h>
#define maxn 505
#define mod 1000000007
#define int long long
using namespace std;
int n, k, tx, ty, uset[maxn * maxn], num[maxn * maxn];
char board[maxn][maxn];
char get_read(){
    char ch = getchar();
    while(ch != '1' && ch != '0')    ch = getchar();
    return ch;
}
int find(int x){
    return x == uset[x] ? uset[x] : uset[x] = find(uset[x]);
}
void unioon(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy)    return;
    uset[fx] = fy;
    num[fy] += num[fx];
}
int quickpow(int a, int b, int p){
    if(b == 0)  return 1;
    int tmp = quickpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)   tmp = (tmp * a) % p;
    return tmp;
}
int inv(int x){
    int p = mod;
    return quickpow(x, p - 2, p);
}
int fx[] = {0, 1, -1, 0, 0};
int fy[] = {0, 0, 0, 1, -1};
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            board[i][j] = get_read();
            uset[i * (n - 1) + j] = i * (n - 1) + j;
            num[i * (n - 1) + j] = 1;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= 4; k++)
            {
                int nx = i + fx[k], ny = j + fy[k];
                if(board[nx][ny] == '1' && board[i][j] == '1')
                {
                    unioon(i * (n - 1) + j, nx * (n - 1) + ny);
                }
            }
        }
    }

    int cnt = 0, ans = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i * (n - 1) + j == uset[i * (n - 1) + j] && board[i][j] == '1')
            {
                cnt++;
                ans = (ans * num[i * (n - 1) + j]) % mod;
                //printf("debug: %lld %lld %lld\n", i, j, num[i * (n - 1) + j]);
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
        board[tx][ty] = '1';
        cnt++;
        ans = (ans * cnt) % mod;
        for(int i = 1; i <= 4; i++)
        {
            int nx = tx + fx[i], ny = ty + fy[i];
            if(board[nx][ny] == '0')    continue;
            if(nx < 1 || ny < 1 || nx > n || ny > n)    continue;
            int f1 = find(tx * (n - 1) + ty);
            int f2 = find(nx * (n - 1) + ny);
            //printf("%lld %lld %lld\n", i, nx, ny);
            if(f1 == f2)  continue;
            ans = (ans * inv(cnt)) % mod;
            //printf("debug1:%lld %lld\n", cnt, inv(cnt));
            ans = (ans * inv(num[f1])) % mod;
            //printf("debug2:%lld\n", ans);
            ans = (ans * inv(num[f2])) % mod;
            //printf("debug3:%lld\n", ans);
            ans = (ans * (num[f1] + num[f2])) % mod;
            cnt--;
            //printf("%lld %lld %lld %lld %lld %lld\n", f1, num[f1], f2, num[f2], ans, cnt);
            unioon(f1, f2);
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}
