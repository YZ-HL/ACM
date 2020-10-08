#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 1000005
using namespace std;
int cnt;
int now = 1;
int n, al[maxn], am[maxn], vis[maxn];
struct tree{
	int val;
	int lf;
	int rt;
} t[maxn];
void dfs(int x, int lf, int rt, int m, int lr){
	int mid = -1;
	for(int i = lf; i <= rt; i++)
		if(al[now] == am[i])
		{
			mid = i;
			break;
		}
	if(mid < 0)	
		return;
	now++;
	if(lr != -1)
		lr ? t[x].lf = cnt + 1 : t[x].rt = cnt + 1;
	t[++cnt].val = am[mid];
	int rot = cnt;
	if(m == 1)
	{
		dfs(rot, lf, mid-1, m, 1);
		dfs(rot, mid+1, rt, m, 0);
	}
	else
	{
		dfs(rot, mid+1, rt, m, 1);
		dfs(rot, lf, mid-1, m, 0);
	}
}
int fir = 0;
void print(int x){
	if(t[x].lf)
		print(t[x].lf);
	if(t[x].rt)
		print(t[x].rt);
	if(!fir)
		printf("%d", t[x].val), fir = 1;
	else
		printf(" %d", t[x].val);
}
int main(void)
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &al[i]), am[i] = al[i];
	sort(am+1, am+n+1);
	dfs(1, 1, n, 1, -1);
	if(now != n+1)
	{
		now = 1;
		cnt = 0;
		memset(t, 0, sizeof(t));
		dfs(1, 1, n, 2, -1);
	}
	if(n == 0)
	{
		printf("YES");
		return 0;
	}
	printf(now == n+1 ? "YES\n" : "NO");
	if(now == n+1)    print(1);
    return 0;
}
