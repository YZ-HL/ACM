#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
using namespace std;
int n, t;
struct Martix{
    int c, r;
    int Board[6][6];
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
Martix quickpow(Martix r, int p){
    if(p == 1)  return r;
    Martix tmp = quickpow(r, p / 2);
    tmp = tmp * tmp;
    if(p & 1)   tmp = tmp * r;
    return tmp;
}
void print(Martix now){
    int nowc = now.c;
    int nowr = now.r;
    for(int i = 1; i <= nowr; i++)
        for(int j = 1; j <= nowc; j++)
            printf(j == nowc ? "%lld\n" : "%lld ", now.Board[i][j]);
}
void inits(){
    ra.c = 3; ra.r = 1;
    ra.Board[1][1] = 6; ra.Board[1][2] = 4; ra.Board[1][3] = 3;
    
    bas.c = 3; bas.r = 3; 
    bas.Board[1][1] = 1; bas.Board[1][2] = 1; bas.Board[1][3] = 0;
    bas.Board[2][1] = 0; bas.Board[2][2] = 0; bas.Board[2][3] = 1;
    bas.Board[3][1] = 1; bas.Board[3][2] = 0; bas.Board[3][3] = 0;
    
    id.c = 3; id.r = 3;
    id.Board[1][1] = 1; id.Board[1][2] = 0; id.Board[1][3] = 0;
    id.Board[2][1] = 0; id.Board[2][2] = 1; id.Board[2][3] = 0;
    id.Board[3][1] = 0; id.Board[3][2] = 0; id.Board[3][3] = 1;
}
signed main(void)
{
    inits();
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        if(n == 2)
            printf("%lld\n", 3);
        else if(n == 3)
            printf("%lld\n", 4);
        else if(n == 4)
            printf("%lld\n", 6);
        else
        {   
            //printf("debug:");
            //print(ra * quickpow(bas, n - 3));
            
            int ans = (ra * quickpow(bas, n - 4)).Board[1][1];
            ans = ((ans % mod) + mod) % mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}