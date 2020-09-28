#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000005
using namespace std;
int t, n, l[maxn], P[maxn];
bool isP[maxn];
void Get_Prime(int lim){
    memset(isP, true, sizeof(isP));
    isP[0] = isP[1] = false;
    for(int i = 2; i <= lim; i++)
    {
        if(isP[i])  P[++P[0]] = i;
        for(int j = 1; j <= P[0] && i * P[j] <= lim; j++)
        {
            isP[P[j] * i] = false;
            if(i % P[j] == 0)
                break;
        }
    }
}
int Solve_SG(int now){
    if(now == 1)
        return 0;
    int r = now;
    int cnt = 0, flag = 0;
    while(!(now & 1))   flag++, now /= 2;
    for(int i = 1; i <= P[0] && now > 1; i++)
    {
        if(P[i] > now)    break;
        while(now % P[i] == 0)  now /= P[i], cnt++;
    }
    if(now > 1) cnt++;
    return flag ? cnt + 1 : cnt;
}
int main(void)
{ 
    scanf("%d", &t);
    Get_Prime(40005);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &l[i]);
        int res = 0;
        for(int i = 1; i <= n; i++)
            res ^= Solve_SG(l[i]);
        printf(res ? "W\n" : "L\n");
    }
    system("pause");
    return 0;
}
