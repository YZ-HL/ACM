#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int n, m;
int calc_2pow(int k){
    if(k == 0)  return 1;
    int bas = 1;
    for(int i = 1; i <= k; i++)
        bas *= 2;
    return bas;
}
int checkS(int m, int part){
    int rm = m % part;
    part /= 4;
    if(rm == 0)
        return 4;
    else if(rm <= part)
        return 1;
    else if(rm <= part * 2)
        return 2;
    else if(rm <= part * 3)
        return 3;
    else
        return 4;
}
int checkR(int d, int s){
    if(d == 0 && s == 1)
        return 90;
    else if(d == 0 && s == 4)
        return -90;
    
    if(d == 90 && s == 4)
        return 90;
    else if(d == 90 && s == 1)
        return -90;

    if(d == 180 && s == 4)
        return 90;
    else if(d == 180 && s == 1)
        return -90;

    if(d == 270 && s == 1)
        return -90;
    else if(d == 270 && s == 4)
        return 90;

    return 0;
}
void calc(int &nx, int &ny, int s_it, int d, int val){
    if(d == 0)
    {
        if(s_it == 1)    nx = nx, ny = ny;
        if(s_it == 2)    nx = nx, ny += val;
        if(s_it == 3)    nx += val, ny += val;
        if(s_it == 4)    nx += val, ny = ny;
    }
    if(d == 90)
    {
        if(s_it == 1)    nx = nx, ny = ny;
        if(s_it == 2)    nx += val, ny = ny;
        if(s_it == 3)    nx += val, ny += val;
        if(s_it == 4)    nx = nx, ny += val;
    }
    if(d == 180)
    {
        if(s_it == 1)    nx += val, ny += val;
        if(s_it == 2)    nx += val, ny = ny;
        if(s_it == 3)    nx = nx, ny = ny;
        if(s_it == 4)    nx = nx, ny += val;
    }
    if(d == 270)
    {
        if(s_it == 1)    nx = nx, ny = ny;
        if(s_it == 2)    nx += val, ny = ny;
        if(s_it == 3)    nx += val, ny += val;
        if(s_it == 4)    nx = nx, ny += val;
    }
}
int my_log2(int x){
    int cnt = 0;
    while(x)
    {
        x /= 2;
        cnt++;
    }
    return cnt - 1;
}
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    int k = my_log2(n);
    int nk = k, d = 0, nx = 1, ny = 1;
    while(nk)
    {
        d = ((d % 360) + 360) % 360;
        int part = calc_2pow(nk * 2); nk--;
        int s_it = checkS(m, part);
        int val = calc_2pow(nk);
        printf("%lld %lld %lld %lld %lld %lld\n", part, s_it, val, d, nx, ny);
        calc(nx, ny, s_it, d, val);
        d += checkR(d, s_it);
    }
    printf("%lld %lld\n", nx, ny);
    return 0;
}

