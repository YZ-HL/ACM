#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int n, m, k, flag;
int ans[maxn], uset[maxn];
int f[maxn], kn[maxn], vis[maxn], ros[maxn], rot[maxn];
int find(int x){
	return x == uset[x] ? x : uset[x] = find(uset[x]); 
}
void unionn(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if(fx == fy)	return;
	uset[fx] = fy;
}
int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    	uset[i] = i;
    for(int i = 1; i <= m; i++)
    	scanf("%d %d", &ros[i], &rot[i]);
    scanf("%d", &k);
    for(int i = 1; i <= k; i++)
    {
    	scanf("%d", &kn[i]);
    	vis[kn[i]] = 1;
    }
    for(int i = 1; i <= m; i++)
    	if(!vis[ros[i]] && !vis[rot[i]])	unionn(ros[i], rot[i]);
    
    for(int i = 0; i <= n - 1; i++)
    	f[find(i)]++;
    for(int i = 0; i <= n - 1; i++)
    	if(f[i])	ans[k+1]++;
    
    for(int i = k; i >= 1; i--)
    {
    	vis[kn[i]] = 0;
    	for(int i = 1; i <= m; i++)
    		if(!vis[ros[i]] && !vis[rot[i]])	unionn(ros[i], rot[i]);
    	memset(f, 0, sizeof(f));
    	for(int j = 0; j <= n - 1; j++)
    		f[find(j)]++;
    	for(int j = 0; j <= n - 1; j++)
    		if(f[j])	ans[i]++;
    }
    
    //for(int i = 1; i <= k + 1; i++)
    //	printf("%d ", ans[i]);
    //putchar('\n');
    
    for(int i = 1; i <= k; i++)
    {
    	if(ans[i] < ans[i+1] - 1)
    		printf("Red Alert: City %d is lost!", kn[i]);
    	else
    		printf("City %d is lost.", kn[i]);
    	if(i != k)
    		putchar('\n');
    }
    if(k == n)
    	printf("\nGame Over.");
    return 0;
}
