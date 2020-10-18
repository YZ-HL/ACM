#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 1005
using namespace std;
int b, s, sum, con[maxn], cop[maxn], ctn[maxn], dp[(1<<25)+5];
struct Product{
	int c;
	int k;
	int p;
} p[maxn];
struct Com{
	int c;
	int k;
} co[maxn][maxn];
int lf, rt;
void getnum(int pos){
	int now = 0;
	for(int i = 1; i <= pos-1; i++)
		now += p[i].k;
	lf = now;
	rt = now + p[pos].k - 1;
}
int dfs(int sta){
	if(dp[sta] < 1e9)
		return dp[sta];
	int maxx = (1<<30);
	for(int i = 1; i <= s; i++)
	{
		int plus = 0, flag = 0;
		for(int j = 1; j <= con[i]; j++)
		{
			getnum(ctn[co[i][j].c]);
			int blank = 0;
			for(int k = lf; k <= rt; k++)
				if(!(sta & (1 << k)))	blank++;
			if(blank < co[i][j].k)
			{
				flag = 1;
				break;
			}
		}
		
		if(flag)	continue;
		
		for(int j = 1; j <= con[i]; j++)
		{
			getnum(ctn[co[i][j].c]);
			for(int k = lf, num = 1; k <= rt && num <= co[i][j].k; k++)
				if(!(sta & (1 << k)))	plus |= (1 << k), num++;
		}
		maxx = min(maxx, dfs((sta | plus)) + cop[i]);
	}
	for(int i = 1; i <= b; i++)
	{
		getnum(i);
		for(int k = lf; k <= rt; k++)
			if(!(sta & (1 << k)))
			{
				maxx = min(maxx, dfs(sta | (1 << k)) + p[i].p);
				break;
			}
	}
	return dp[sta] = maxx;
}
int main(void)
{
	memset(dp, 0x3f, sizeof(dp));
    scanf("%d", &b);
    for(int i = 1; i <= b; i++)
    {
    	scanf("%d %d %d", &p[i].c, &p[i].k, &p[i].p);
    	ctn[p[i].c] = i;
    	sum += p[i].k;
    }
    dp[(1 << sum) - 1] = 0;
    scanf("%d", &s);
    for(int i = 1; i <= s; i++)
    {
    	scanf("%d", &con[i]);
    	for(int j = 1; j <= con[i]; j++)
    		scanf("%d %d", &co[i][j].c, &co[i][j].k);
    	scanf("%d", &cop[i]); 
    }
    printf("%d\n", dfs(0));
    return 0;
}
/*
方向：状态压缩动态规划
所需购买物品最多25件，完全可用二进制压缩表示
dp[10^7.5 ???] = 最小花费
最小花费是具有子结构性质可继承的
考虑小情况：
[000...0] = 一个都没买
套餐(1, 3)
{000...0} |= 111 -> {111000...0}
也就是说
初始化dp为0x3f,dp[000...0] = 0;
dp[bits] = 不断尝试购买;
最后
dp[111....1] -> 答案
//统一位数：k1.1,k1.2,...,k1.k,k2.1,.....
*/