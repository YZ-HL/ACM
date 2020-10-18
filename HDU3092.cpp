#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 3005
#define int long long
using namespace std;
int s, m;
int ans[maxn], pri[maxn], pnum[maxn];
double dp[maxn];
int gcd(int x, int y){
	return y ? gcd(y, x % y) : x;
}
int lcm(int x, int y){
	return x * y / gcd(x, y);
}
void init(){
	memset(pri, true, sizeof(pri));
	//pnum[++pnum[0]] = 1;
	for(int i = 2; i <= 3000; i++)
	{	
		for(int j = 2; pri[i] && j * j <= i; j++)
			if(i % j == 0)    pri[i] = false;
		if(pri[i])
			pnum[++pnum[0]] = i;
	}
}
signed main(void)
{
	init();
    while(~scanf("%lld %lld", &s, &m))
    {
    	memset(dp, 0, sizeof(dp));
    	for(int i = 0; i <= s; i++)    ans[i] = 1;
    	for(int i = 1; i <= pnum[0] && pnum[i] <= s; i++)
    	{
    		for(int j = s; j >= pnum[i]; j--)
    		{
    			for(int k = pnum[i], c = 1; j - k >= 0; k *= pnum[i], c++)
    			{
    				if(dp[j] < dp[j - k] + c * log10(pnum[i]))
    				{
    					dp[j] = dp[j - k] + c * log10(pnum[i]);
    					ans[j] = ((ans[j - k] % m) * (k % m)) % m;
    				}
    			}
    		}
    	}
	    printf("%lld\n", ans[s]);
	}
    return 0;
}
/*
dp[i] = max(LCM) ?
当前凑出数字为i
互斥时LCM最大
何时互斥？
元素均为素数之幂次时？
********重要思想，log取对数减小数据规模防爆炸
dp[1] = 1;
dp[2] = 2;
dp[2] = LCM(dp[1], 1) 
dp[3] = max(LCM(dp[2], 1), LCM(dp[1], 2));
dp[i] = max(LCM(dp[i-k], k));
*/