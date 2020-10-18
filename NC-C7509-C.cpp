#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 1000005
using namespace std;
int t, k, n;
int used[maxn], pri[maxn], mu[maxn];
bool isp[maxn];
void euler(int maxx){
	mu[1] = 1;
	memset(isp, true, sizeof(isp));
	for(int i = 2; i <= maxx; i++)
	{
		if(isp[i])	pri[++pri[0]] = i, mu[i] = -1;
		for(int j = 1; j <= pri[0] && i * pri[j] <= maxx; j++)
		{
			isp[i * pri[j]] = false;
			if(i % pri[j] == 0)
			{
				mu[i * pri[j]] = 0;
				break;
			}
			mu[i * pri[j]] = -mu[i];
		}
	}
}
int dfs(int n, int k){
	if(k == 0)	
		return n;
	int now = n, cnt = 0;
	for(int i = 1; i <= pri[0]; i++)
	{
		if(now % pri[i] == 0)
			now /= pri[i], cnt++;
		if(pri[i] > now)
			break;
	}
	if(n == 1)
		return dfs(n + 1, k - 1);
	else if(now == 1)
		return dfs(n + (cnt & 1 ? -1 : 1), k - 1);
	return dfs(n + 0, k - 1);
}
int main(void)
{
    euler(1000000);
    scanf("%d", &t);
    k = 1000;
    while(t--)
    {
    	int k1 = n + mu[n];
    	int k2 = n + mu[n + mu[n]];
    }
    return 0;
}
