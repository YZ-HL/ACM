#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int a, b, flag, isx[maxn], used[maxn], vis[maxn];
void dfs(int x, int dep){
    if(x == 1)
    {
        flag = dep;
        return;
    }
    if(vis[x])    return;
    vis[x] = 1;   used[x]++;
    int r = x, sum = 0;
    while(r)
        sum += (r % 10) * (r % 10), r /= 10;
    dfs(sum, dep + 1);
    if(flag)    
        isx[x] = flag - dep;
    vis[x] = 0;
    //printf("%d %d %d\n", x, dep, isx[x]);
    if(isx[x] == -1)    isx[x] = 0;
}
bool isprime(int x){
    bool flag = true;
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
        {
            flag = false;
            break;
        }
    return flag;
}
int main(void)
{
    memset(isx, -1, sizeof(isx));
    scanf("%d %d", &a, &b);
    //dfs(19, 1);
    //system("pause");
    for(int i = a; i <= b; i++)
    {
        if(isx[i] == -1)
        {
            flag = 0;
            dfs(i, 1);
        }
    }
    int rflag = 0;
    for(int i = a; i <= b; i++)
        if(isx[i] && used[i] == 1)  
            printf("%d %d\n", i, (isprime(i) ? 2 * isx[i] : isx[i])), rflag = 1;
    if(!rflag)
        printf("SAD\n");
    return 0;
}