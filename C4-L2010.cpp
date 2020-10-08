#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 105
using namespace std;
int n, m, k;
int uset[maxn], fuc[maxn][maxn];
int find(int x){
	return x == uset[x] ? x : uset[x] = find(uset[x]);
}
int unionn(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if(fx == fy)	return 0;
	uset[fx] = fy;
}
int main(void)
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++) uset[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u, v, b;
		scanf("%d %d %d", &u, &v, &b);
		b == 1 ? unionn(u, v) : fuc[u][v] = fuc[v][u] = 1;
	}
	for(int i = 1; i <= k; i++)
	{
		int u, v, fu, fv;
		scanf("%d %d", &u, &v);
		fu = find(u);
		fv = find(v);
		if(fu == fv && !fuc[u][v])
			printf("No problem");
		else if(fu != fv && !fuc[u][v])
			printf("OK");
		else if(fu == fv && fuc[u][v])
			printf("OK but...");
		else
			printf("No way");
		if(i != k)
			putchar('\n');
	}
    return 0;
}
