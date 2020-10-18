#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int n, f[maxn], m[maxn];
int cnt, now = 1, ans[maxn];
struct tree{
	int val;
	int lf;
	int rt;
} t[maxn];
void dfs(int lf, int rt, int fa, int lr){
	int s = -1;
	for(int i = lf; i <= rt; i++)
		if(m[i] == f[now])
		{
			s = i;
			break;
		}
	if(s == -1)    return;
	int nrt = ++cnt;
	t[nrt].val = m[s];
	now++;
	if(fa)
		lr ? t[fa].lf = nrt : t[fa].rt = nrt;
	dfs(lf, s - 1, nrt, 0);
	dfs(s + 1, rt, nrt, 1);
}
void bfs(){
	queue<tree> q1;
	q1.push(t[1]);
	while(!q1.empty())
	{
		tree tmp = q1.front();
		ans[++ans[0]] = tmp.val;
		q1.pop();
		if(tmp.lf)	q1.push(t[tmp.lf]);
		if(tmp.rt)	q1.push(t[tmp.rt]);
	}
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    	scanf("%d", &m[i]);
    for(int i = 1; i <= n; i++)
    	scanf("%d", &f[i]);
    dfs(1, n, 0, 0);
    bfs();
    for(int i = 1; i <= ans[0]; i++)
    	printf(i == ans[0] ? "%d" : "%d ", ans[i]);
    return 0;
}
