#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int a, b, c;
int qpow(int a, int b, int p){
    if(b == 0)  return 1;
    int tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)   tmp = (tmp * a) % p;
    return tmp;   
}
int two[] = {6, 2, 4, 8};
int three[] = {1, 3, 9, 7};
int four[] = {6, 4, 6, 4};
int seven[] = {1, 7, 9, 3};
int eight[] = {6, 8, 4, 2};
int nine[] = {1, 9, 1, 9};
signed main(void)
{
    scanf("%lld %lld %lld", &a, &b, &c);
    int res = qpow(b, c, 4);
    int bas = a % 10;
    if(bas == 0 || bas == 1 || bas == 5 || bas == 6)    printf("%lld\n", bas);
    else if(bas == 2)
        printf("%lld\n", two[res]);
    else if(bas == 3)
        printf("%lld\n", three[res]);
    else if(bas == 4)
        printf("%lld\n", four[res]);
    else if(bas == 7)
        printf("%lld\n", seven[res]);
    else if(bas == 8)
        printf("%lld\n", eight[res]);
    else if(bas == 9)
        printf("%lld\n", nine[res]);
    return 0;
}
