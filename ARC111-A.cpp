#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n, m;

int getpow(int x){
    if(x == 0)  return 1;
    return 10 * getpow(x - 1);
}

int qpow(int a, int b, int p){
    if(b == 0)  return 1;
    int tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)   tmp = (tmp * a) % p;
    return tmp;
}
int inv(int x){
    return qpow(x, m - 2, m);
}
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    
    //int res = getpow(n) / m;
    
    printf("%lld\n", qpow(10, n, m * m) / m);
    
    return 0;
}
/* 1 6 1
 * 2 6 4
 * 3 6 4
 * 4 6 4
 */ 

