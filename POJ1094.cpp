#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 105
using namespace std;
int n, m, c[maxn];
int dis[maxn][maxn];
vector<int> topo;
bool dfs(int x){
    bool flag = true;
    c[x] = -1;
    for(int i = 1; i <= n; i++)
    {
        if(dis[x][i] == 1)
        {
            if(c[i] < 0)
                return false;
            else if(!c[i])
                flag &= dfs(i);
        }
    }
    c[x] = 1;
    topo.push_back(x);
    return flag;
}
bool toposort(){
    memset(c, 0, sizeof(c));
    topo.clear();
    for(int u = 1; u <= n; u++)
        if(!c[u])
            if(!dfs(u))    
                return false;
    
    reverse(topo.begin(), topo.end());
    return true;
}
bool check(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
    int maxx = -1;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            maxx = max(maxx, dis[topo[i-1]][topo[j-1]]);

    return maxx < 1e9;
}
int main(void)
{
    //freopen("out.txt", "w", stdout);

    while(scanf("%d %d", &n, &m) && n)
    {
        memset(dis, 0x3f, sizeof(dis));
        for(int i = 1; i <= n; i++)    dis[i][i] = 0;
        
        int flag = 0, fail = 0;
        for(int i = 1; i <= m; i++)
        {
            char tmp[5];
            scanf("%s", tmp);
            int u = tmp[0]-'A'+1;
            int v = tmp[2]-'A'+1;
            dis[u][v] = 1;
            if(!fail && !flag)
            {
                fail = toposort() ? 0 : i;
                if(!fail && check())    flag = i;
            }
        }
        if(fail)
            printf("Inconsistency found after %d relations.\n", fail);
        else if(!flag)
            printf("Sorted sequence cannot be determined.\n");
        else
        {
            printf("Sorted sequence determined after %d relations: ", flag);
            for(int i = 0; i < topo.size(); i++)
                putchar(topo[i]+'A'-1);
            putchar('.');
            putchar('\n');
        }
    }
    system("pause");
    return 0;
}
