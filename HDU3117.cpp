#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, mod = 10000;
struct Martix{
    int c, r;
    int Board[4][4];
    Martix operator * (const Martix &A){
        Martix res;
        res.r = r;
        res.c = A.c;
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
            {
                res.Board[i][j] = 0;
                for(int k = 1; k <= c; k++)
                    res.Board[i][j] = (res.Board[i][j] + ((Board[i][k] % mod) * (A.Board[k][j] % mod))) % mod;
            } 
        return res;
    }
} bas, ra, id;
void print(Martix now){
    int nowc = now.c;
    int nowr = now.r;
    for(int i = 1; i <= nowr; i++)
        for(int j = 1; j <= nowc; j++)
            printf(j == nowc ? "%lld\n" : "%lld ", now.Board[i][j]);
}
Martix quickpow(Martix r, int p){
    if(p == 1)  return r;
    Martix tmp = quickpow(r, p / 2);
    tmp = tmp * tmp;
    if(p & 1)   tmp = tmp * r;
    return tmp;
}
void inits(){
    ra.c = 2; ra.r = 1;
    ra.Board[1][1] = 1; ra.Board[1][2] = 1;
    bas.c = 2; bas.r = 2; 
    bas.Board[1][1] = 1; bas.Board[1][2] = 1;
    bas.Board[2][1] = 1; bas.Board[2][2] = 0;
    id.c = 2; id.r = 2;
    id.Board[1][1] = 1; id.Board[1][2] = 0;
    id.Board[2][1] = 0; id.Board[2][2] = 1;
}
signed main(void)
{
    inits();
    while(~scanf("%lld", &n))
    {
        if(n == 0)
            printf("%lld\n", 0);
        else if(n == 1 || n == 2)
            printf("%lld\n", 1);
        else if(n <= 39)
        {
            mod = 100000000;
            printf("%lld\n", (ra * quickpow(bas, n-2)).Board[1][1]);
        }
        else
        {
            mod = 10000;
            double tmp = -0.5*log10(5) + n * log10((1+sqrt(5)) / 2);
            double ans = pow(10.0, (tmp - floor(tmp)) + 3);
            printf("%04lld...%04lld\n", ((int)ans)%10000, (ra * quickpow(bas, n-2)).Board[1][1]);
        }
    }
    return 0;
}