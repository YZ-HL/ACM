#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 1000005
using namespace std;
int n, m, s, d;
int vis[maxn];
int val[maxn], dis[maxn], pre[maxn], ans1[maxn], ans2[maxn], tmp[maxn];
int k, head[maxn];
struct Edge{
	int to;
	int nxt;
	int weight;
} E[maxn];
void Build(int u, int v, int w){
	E[k].to = v;
	E[k].nxt = head[u];
	E[k].weight =w;
	head[u] = k++;
}
struct Point{
	int num;
	int dis;
	int val;
};
bool operator < (const Point &A, const Point &B){
	return A.dis == B.dis ? A.val < B.val : A.dis > B.dis;
}
priority_queue<Point> q1;
void Dij(int s, int t){
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	ans1[s] = 1;
	ans2[s] = val[s];
	q1.push((Point){s, 0});
	while(!q1.empty())
	{
		Point tmp = q1.top();
		q1.pop();
		//printf("%d %d\n", tmp.num, tmp.dis);
		int nows = tmp.num, nowdis = tmp.dis;
		//if(nowdis != dis[nows])    continue;
		if(vis[nows])	continue;
		vis[nows] = 1;
		for(int i = head[nows]; ~i; i = E[i].nxt)
		{
			if(dis[E[i].to] > dis[nows] + E[i].weight)
			{
				dis[E[i].to] = dis[nows] + E[i].weight;
				pre[E[i].to] = nows;
				ans1[E[i].to] = ans1[nows];
				ans2[E[i].to] = ans2[nows] + val[E[i].to];
				q1.push((Point){E[i].to, dis[E[i].to], ans2[E[i].to]});
			}
			else if(dis[E[i].to] == dis[nows] + E[i].weight)
			{
				ans1[E[i].to] += ans1[nows];
				if(ans2[nows] + val[E[i].to] > ans2[E[i].to])
				{
					ans2[E[i].to] = ans2[nows] + val[E[i].to];
					pre[E[i].to] = nows;
					q1.push((Point){E[i].to, dis[E[i].to], ans2[E[i].to]});
				}				
			}
		}
	}
}
int main(void)
{
    memset(head, -1, sizeof(head));
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for(int i = 0; i <= n - 1; i++)
    	scanf("%d", &val[i]);
    for(int i = 1; i <= m; i++)
    {
    	int u, v, w;
    	scanf("%d %d %d", &u, &v, &w);
    	Build(u, v, w);
    	Build(v, u, w);
    }
    Dij(s, d);
    printf("%d %d\n", ans1[d], ans2[d]);
    int now = d, cnt = 0;
    while(now != s)
    {
    	tmp[++cnt] = now;
    	now = pre[now];	
    }
    //for(int i = 1; i <= n; i++)
    //	printf("%d\n", ans1[i]);
    tmp[++cnt] = s;
    for(int i = cnt; i >= 1; i--)
   		printf(i == 1 ? "%d" : "%d ", tmp[i]); 
    return 0;
}