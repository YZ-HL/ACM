#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int n, cnt, now;
int m[maxn], b[maxn];
struct tree{
	int val;
	int lf;
	int rt;
} t[maxn];
void Build(int lf, int rt, int fa, int md){
	int s = -1;
	for(int i = lf; i <= rt; i++)
		if(m[i] == b[now])
		{
			s = i;
			break;
		}
	if(s == -1)
		return;
	int nrt = ++cnt;
	t[nrt].val = m[s]; now--;
	if(fa)
		md ? t[fa].lf = nrt : t[fa].rt = nrt;
	Build(s+1, rt, nrt, 0);
	Build(lf, s-1, nrt, 1);
}
void bfs(){
	queue<tree> q1;
	q1.push(t[1]);
	int fir = 1;
	while(!q1.empty())
	{
		tree now = q1.front();
		q1.pop();
		if(fir)
			printf("%d", now.val), fir = 0;
		else
			printf(" %d", now.val);
		if(now.lf)
			q1.push(t[now.lf]);
		if(now.rt)
			q1.push(t[now.rt]);
	}
}
int main(void)
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &m[i]);
	now = n;
	Build(1, n, 0, 0);
    bfs();
    return 0;
}
