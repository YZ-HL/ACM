#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m, k, d;
map<string, int> mp;
struct Edge{
    int to;
    int nxt;
    int weight;
}E[maxn];
struct Ga{
    int vaild;
    int num;
    int sum_dist;
    int min_dist;
    double avg_dist;
}ans[maxn];
bool cmp(const Ga &A, const Ga &B){
    if(A.vaild != B.vaild)
        return A.vaild > B.vaild;
    if(A.min_dist != B.min_dist)
        return A.min_dist > B.min_dist;
    return fabs(A.avg_dist - B.avg_dist) <= 1e-6 ? A.num < B.num : A.avg_dist < B.avg_dist;
}
int kk, head[maxn];
void Build(int u, int v, int w){
    E[kk].to = v;
    E[kk].nxt = head[u];
    E[kk].weight = w;
    head[u] = kk++;
}
int str2int(string now){
    if(mp.count(now))    return mp[now];
    int val = 0, flag = 0;
    if(now[0] == 'G')    flag++;
    for(int i = flag; i < now.size(); i++)
        val = val * 10 + now[i] - '0';
    mp[now] = flag ? n + val : val;
    return mp[now];
}
int dis[maxn], inq[maxn];
void spfa(int s){
    queue<int> q1;
    memset(inq, 0, sizeof(inq));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q1.push(s); inq[s] = 1;
    while(!q1.empty())
    {
        int now = q1.front(); q1.pop(); inq[now] = 0;
        for(int i = head[now]; ~i; i = E[i].nxt)
        {
            if(dis[E[i].to] > dis[now] + E[i].weight)
            {
                dis[E[i].to] = dis[now] + E[i].weight;
                if(!inq[E[i].to])
                {
                    inq[E[i].to] = 1;
                    q1.push(E[i].to);
                }
            }
        }
    }
}
int main(void)
{
    //freopen("tmp.txt", "w", stdout);
    memset(head, -1, sizeof(head));
    scanf("%d %d %d %d", &n, &m, &k, &d);
    for(int i = 1; i <= k; i++)
    {
        string u, v; int w;
        cin >> u >> v >> w;
        int un = str2int(u);
        int vn = str2int(v);
        Build(un, vn, w);
        Build(vn, un, w);
    }
    for(int i = n + 1; i <= n + m; i++)
    {
        ans[i - n].min_dist = (1 << 30);
        spfa(i);
        //printf("%d %d %d %d\n", dis[1], dis[2], dis[3], dis[4]);
        int fail = 0;
        for(int j = 1; j <= n; j++)
        {
            if(dis[j] > d)
            {
                fail = 1;
                break;
            }
            ans[i - n].sum_dist += dis[j];
            //printf("debug: %d %d\n", ans[i - n].min_dist, dis[j]);
            ans[i - n].min_dist = min(ans[i - n].min_dist, dis[j]);
        }        
        if(fail) 
            ans[i - n].vaild = 0;
        else
        {
            ans[i - n].vaild = 1;
            ans[i - n].avg_dist = 1.0 * ans[i - n].sum_dist / n;
            ans[i - n].num = i - n;
        }           
    }
    sort(ans + 1, ans + m + 1, cmp);
    if(ans[1].vaild == 0)
        printf("No Solution\n");
    else
    {
        printf("G%d\n", ans[1].num);
        printf("%.1lf %.1lf\n", 1.0 * ans[1].min_dist, round(ans[1].avg_dist * 10) / 10);
    }
    return 0;
}
