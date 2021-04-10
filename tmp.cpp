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
int main(void)
{
    scanf("%d %d", &n, &m);
    int k = log2(n);
    int nx = 1, ny = 1, nk = k, d = 0;
    while(nk > 1)
    {
        int part = calc_2pow(nk * 2);
        m %= part;
        part /= 4;
        if(m <= part)
        {
            d += 90;
            nk--;
        }
        else if(m <= part * 2)
        {
            nx = nx;
            ny = ny + calc_2pow(nk - 1);
            nk--;
        }
        else if(m <= part * 3)
        {
            nx = nx + calc_2pow(nk - 1);
            ny = ny + calc_2pow(nk - 1);
            nk--;
        }
        else
        {
            nx = nx + calc_2pow(nk - 1);
            ny = ny;
            nk--;
            d -= 90;
        }
    }
    d = ((d % 360) + 360) % 360;
    if(d == 0)
    {
        if(m % 4 == 0)
            nx = nx, ny = ny;
        else if(m % 4 == 1)
            nx = nx, ny++;
        else if(m % 4 == 2)
            nx++, ny++;
        else
            nx++, ny = ny;
    }
    if(d == 90)
    {
        if(m % 4 == 0)
            nx = nx, ny = ny;
        else if(m % 4 == 1)
            nx++, ny = ny;
        else if(m % 4 == 2)
            nx++, ny++;
        else
            nx = nx, ny++;
    }
    if(d == 180)
    {
        if(m % 4 == 0)
            nx++, ny++;
        else if(m % 4 == 1)
            nx++, ny = ny;
        else if(m % 4 == 2)
            nx = nx, ny = ny;
        else
            nx = nx, ny++;
    }
    if(d == 270)
    {
        if(m % 4 == 0)
            nx++, ny++;
        else if(m % 4 == 1)
            nx = nx, ny++;
        else if(m % 4 == 2)
            nx = nx, ny = ny;
        else
            nx++, ny = ny;
    }
    printf("%d %d\n", nx, ny);
    return 0;
}
