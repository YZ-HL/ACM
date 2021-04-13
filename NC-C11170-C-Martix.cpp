#include <bits/stdc++.h>
#define maxn 15
#define mod 100019
#define int long long
using namespace std;
int n;
struct Matrix{
    int M[maxn][maxn];
}I, B;
Matrix operator * (const Matrix &A, const Matrix &B){
    Matrix res;
    memset(res.M, 0, sizeof(res.M));
    for(int i = 1; i <= 9; i++)    
        for(int j = 1; j <= 9; j++)
            for(int k = 1; k <= 9; k++)
                res.M[i][j] = (res.M[i][j] + A.M[i][k] * B.M[k][j]) % mod;
    return res;
}
Matrix quickpow(Matrix a, int b){
    if(b == 0)  return I;
    Matrix tmp = quickpow(a, b / 2);
    tmp = (tmp * tmp);
    if(b & 1)   tmp = (tmp * a);
    return tmp;
}
void init(){
    for(int i = 1; i <= 9; i++)    I.M[i][i] = 1;
    for(int i = 1; i <= 9; i++)
        for(int j = i; j <= 9; j++)
            B.M[i][j] = 1;
}
void Print(Matrix now){
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
            printf(j == 9 ? "%d\n" : "%d ", now.M[i][j]);
}
signed main(void)
{
    init();    
    scanf("%lld", &n);
    Matrix res = quickpow(B, n - 1);
    int ans = 0;
    for(int i = 1; i <= 9; i++)
        for(int j = i; j <= 9; j++)
            ans = (ans + res.M[i][j]) % mod;
    Print(res);
    printf("%lld\n", ans);    
    return 0;
}
