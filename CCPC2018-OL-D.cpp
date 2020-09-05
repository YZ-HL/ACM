#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int ansb[maxn], ansc[maxn];
void solve(int now){
    if(now & 1)
    {
        ansb[now] = (now*now-1)/2;
        ansc[now] = ansb[now]+1;
    }
    else
    {
        ansb[now] = (now*now-4)/4;
        ansc[now] = ansb[now]+2;
    }    
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, a;
        scanf("%d %d", &n, &a);
        if(n == 1)
            printf("%d %d\n", 1, a+1);
        else if(n == 2)
        {
            if(!ansb[a])
                solve(a);
            printf("%d %d\n", ansb[a], ansc[a]);
        }
        else
            printf("%d %d\n", -1, -1);
    }
    system("pause");
    return 0;
}
