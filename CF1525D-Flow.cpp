#include <bits/stdc++.h>
using namespace std;
bool vis[200001];
int dist[200001];                                                            //vis是spfa访问标记及増广访问标记,dist是每个点距离标号
int n, m, s, t, ans = 0;                                                     //s是起点，t是终点，ans是费用答案
int nedge = -1, p[200001], c[200001], cc[200001], nex[200001], head[200001]; //nedge为边编号
//p,c,cc,nex表编号为i的边终点,流量,费用,下一条边，head表编号为i的点射出的最后一边
void addedge(int x, int y, int z, int zz)
{
    p[++nedge] = y;
    c[nedge] = z;
    cc[nedge] = zz;
    nex[nedge] = head[x];
    head[x] = nedge;
} //建边（数组模拟边表倒挂）
bool spfa(int s, int t)
{
    memset(vis, 0, sizeof vis); //深搜前先清0
    for (int i = 0; i <= n; i++)
        dist[i] = 1e9;
    dist[t] = 0;
    vis[t] = 1; //SPFA维护距离标号要倒着跑，维护出到终点的最短路径
    deque<int> q;
    q.push_back(t); //使用了SPFA的队列优化
    while (!q.empty())
    {
        int now = q.front();
        q.pop_front();
        for (int k = head[now]; k > -1; k = nex[k])
        { //下一行的k^1可保证正流
            if (c[k ^ 1] && dist[p[k]] > dist[now] - cc[k])
            {                                   //SPFA倒着跑故c[k]对应反向边是为正
                dist[p[k]] = dist[now] - cc[k]; //已经倒着，建边时反向边权为负，故负负得正
                if (!vis[p[k]])
                {
                    vis[p[k]] = 1;
                    if (!q.empty() && dist[p[k]] < dist[q.front()])
                        q.push_front(p[k]);
                    else
                        q.push_back(p[k]); //距离最短的放前面，否则放队末
                }
            }
        }
        vis[now] = 0; //此点搜完退出就要清0
    }
    return dist[s] < 1e9; //判断起点终点是否连通
}
int dfs(int x, int low)
{ //这里就是进行増广了
    if (x == t)
    {
        vis[t] = 1;
        return low;
    }
    int used = 0, a;
    vis[x] = 1; //类似dinic
    for (int k = head[x]; k > -1; k = nex[k])
        if (!vis[p[k]] && c[k] && dist[x] - cc[k] == dist[p[k]])
        {                                         //未访问,有流量,此边在最短路径上
            a = dfs(p[k], min(c[k], low - used)); //往下一个点深搜且流量降低
            if (a)
                ans += a * cc[k], c[k] -= a, c[k ^ 1] += a, used += a; //深搜有流：加钱,减流,加流,递归流
            if (used == low)
                break; //流量流完了可以退出（本题可忽略）
        }              //这题最大流不定,故开了1E9无限大
    return used;
}

int costflow()
{                 //开始跑
    int flow = 0; //开始时流量为0
    while (spfa(s, t))
    {               //判断起点终点是否连通，不连通则满流退出
        vis[t] = 1; //只是为了第一次可以进入vis
        while (vis[t])
        {
            memset(vis, 0, sizeof vis); //先清零，看下面的深搜能否更新到终点
            flow += dfs(s, 1e9);        //一直増广直到走不到为止
        }
    }
    return flow; //返回最大流，费用在ans里
}
int a[5005];
int main()
{
    memset(nex, -1, sizeof nex);
    memset(head, -1, sizeof head);     //初始化nex与head数组
    scanf("%d", &n);
    s = 0; t = n + 1;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] == 1)
            addedge(s, i, 1, 0), addedge(i, s, 0, 0);
        else
            addedge(i, t, 1, 0), addedge(t, i, 0, 0);
        if(i != n)
            addedge(i, i + 1, n, 1), addedge(i + 1, i, 0, -1),
            addedge(i + 1, i, n, 1), addedge(i, i + 1, 0, -1);
    }
    costflow();
    printf("%d", ans); //输入最大流时流量与费用
    return 0;
}