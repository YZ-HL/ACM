#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m;
int calc_2pow(int k){
    if(k == 0)  return 1;
    int bas = 1;
    for(int i = 1; i <= k; i++)
        bas *= 2;
    return bas;
}
int calc(int &d, int &nx, int &ny, int sta, int val){
    //printf("%d %d %d %d\n", nx, ny, d, sta);
    d = ((d % 360) + 360) % 360;
    if(d == 0)
    {
        if(sta == 1)
            nx = nx, ny = ny;
        else if(sta == 2)
            nx = nx, ny += val;
        else if(sta == 3)
            nx += val, ny += val;
        else
            nx += val, ny = ny;
    }
    if(d == 90)
    {
        if(sta == 1)
            nx = nx, ny = ny;
        else if(sta == 2)
            nx += val, ny = ny;
        else if(sta == 3)
            nx += val, ny += val;
        else
            nx = nx, ny += val;
    }
    if(d == 180)
    {
        if(sta == 1)
            nx += val, ny += val;
        else if(sta == 2)
            nx += val, ny = ny;
        else if(sta == 3)
            nx = nx, ny = ny;
        else
            nx = nx, ny += val;
    }
    if(d == 270)
    {
        if(sta == 1)
            nx += val, ny += val;
        else if(sta == 2)
            nx = nx, ny += val;
        else if(sta == 3)
            nx = nx, ny = ny;
        else
            nx += val, ny = ny;
    }
}
int main(void)
{
    scanf("%d %d", &n, &m);
    int k = log2(n);
    int nx = 1, ny = 1, nk = k, d = 0, part;
    while(nk)
    {
        printf("%d %d %d %d\n", nk, nx, ny, d);
        part = calc_2pow(nk * 2); m %= part; part /= 4; nk--;
        if(m <= part && m)
        {
            int sta = 0;
            if(d == 0)    sta = 1;
            else if(d == 90)     sta = 1;
            else if(d == 180)    sta = 2;
            else if(d == 270)    sta = 3;
            calc(d, nx, ny, sta, calc_2pow(nk));
            d += 90;
        }
        else if(m <= part * 2 && m)
        { 
            int sta = 0;
            if(d == 0)    sta = 2;
            else if(d == 90)     sta = 4;
            else if(d == 180)    sta = 1;
            else if(d == 270)    sta = 2;
            calc(d, nx, ny, sta, calc_2pow(nk));
        }
        else if(m <= part * 3 && m)
        {
            int sta = 0;
            if(d == 0)    sta = 2;
            else if(d == 90)     sta = 3;
            else if(d == 180)    sta = 3;
            else if(d == 270)    sta = 1;
            calc(d, nx, ny, sta, calc_2pow(nk));
        }
        else
        {
            int sta = 0;
            if(d == 0)    sta = 4;
            else if(d == 90)     sta = 2;
            else if(d == 180)    sta = 3;
            else if(d == 270)    sta = 4;
            calc(d, nx, ny, sta, calc_2pow(nk));
            d -= 90;
        }
    }
    printf("%d %d\n", nx, ny);
    return 0;
}
