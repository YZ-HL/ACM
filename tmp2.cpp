#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m, ans, vis[maxn];
vector<int> G[maxn], col;
set<vector<int> > s1;
void dfs(int now, int cnt){
    printf("debug: %d %d %d %d %d\n", now, cnt, col[1], col[2], col[3]);
    if(cnt == n)
    {
        int flag1 = 1, flag2 = 1, flag3 = 1;
        for(int i = 0; i < G[now].size(); i++)
        {
            if(col[G[now][i]] == 1)    flag1 = 0;
            if(col[G[now][i]] == 2)    flag2 = 0;
            if(col[G[now][i]] == 3)    flag3 = 0;
        }
        if(flag1) {
            col[now] = 1;
            if(!s1.count(col))
                s1.insert(col);
            for(auto &p : s1)
                cout << p << ' ';
            printf("bug1\n");
        }
        if(flag2) {
            col[now] = 2;
            if(!s1.count(col))
                s1.insert(col);
            for(auto &p : s1)
                cout << p << ' ';
            printf("bug1\n");
        }
        if(flag3) {
            col[now] = 3;
            if(!s1.count(col))
                s1.insert(col);
            for(auto &p : s1)
                cout << p << ' ';
            printf("bug1\n");
        }
        return;
    }
    int flag1 = 0, flag2 = 0, flag3 = 0;
    for(int i = 0; i < G[now].size(); i++)
    {
        if(col[G[now][i]] == 1)    flag1 = 1;
        if(col[G[now][i]] == 2)    flag2 = 1;
        if(col[G[now][i]] == 3)    flag3 = 1;
    }
    for(int i = 0; i < G[now].size(); i++)
    {
        if(col[G[now][i]] == 0)
        {
            if(!flag1) {
                col[now] = 1;
                dfs(G[now][i], cnt + 1);
                col[now] = 0;
            }
            if(!flag2) {
                col[now] = 2;
                dfs(G[now][i], cnt + 1);
                col[now] = 0;
            }
            if(!flag3) {
                col[now] = 3;
                dfs(G[now][i], cnt + 1);
                col[now] = 0;
            }
        }
    }
    vis[now] = 0;
}
int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)    col.push_back(0);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1, 1);
    printf("%d\n", (int)s1.size());
    return 0;
}
