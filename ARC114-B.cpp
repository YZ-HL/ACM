#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int n, uset[maxn];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unioon(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)    return;
    uset[fx] = fy;
}
long long qpow(long long a, long long b, long long p){
    if(b == 0)  return 1;
    long long tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)   tmp = (tmp * a) % p;
    return tmp;
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)    uset[i] = i;
    for(int i = 1; i <= n; i++)
    {
        int tmp; scanf("%d", &tmp);
        unioon(tmp, i);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(uset[i] == i)    cnt++;
    printf("%lld\n", qpow(2, cnt, 998244353) - 1);
    return 0;
}
