#include <bits/stdc++.h>
#define int int
#define maxn 800005
#define mod 3
using namespace std;
int n;
char r[maxn];
char get_char(){
    char ch = getchar();
    while(ch != 'W' && ch != 'B' && ch != 'R')    ch = getchar();
    return ch;
}
int jc[maxn], inv[maxn];
int qpow(int a, int b, int p){
    if(b == 0)    return 1;
    int tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)   tmp = (tmp * a) % p;
    return tmp;
}
void get_jc(){
    jc[0] = 1;
    for(int i = 1; i <= n; i++)
        jc[i] = (jc[i - 1] * i);
}
int C(int a, int b, int p) {
    if (b < a)    return 0;
    int s = jc[a] * jc[b - a] % p;
    return jc[b] * qpow(s, p - 2, p) % p;
}

int lucas(int x, int y, int p) {
    if (x == 0)    return 1;
    return lucas(x / p, y / p, p) * C(x % p, y % p, p) % p;
}

int tra(char ch){
    //putchar(ch);
    if(ch == 'B')    return 1;
    if(ch == 'W')    return 2;
    if(ch == 'R')    return 0;
    return -1;
}
signed main(void)
{   
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        r[i] = get_char();
    get_jc();
    int res = 0;
    for(int i = 0; i <= n - 1; i++)
    {
        res = (res + tra(r[i + 1]) * lucas(i, n - 1, mod)) % mod;
        //printf("%d\n", res);
    }
    if((n + 1) & 1)
        res = -res;
    res = ((res % mod) + mod) % mod;
    if(res == 1)
        printf("B\n");
    else if(res == 2)
        printf("W\n");
    else
        printf("R\n");
    return 0;
}
