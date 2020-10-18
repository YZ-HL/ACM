#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 10005
using namespace std;
int b, s, sum;
int con[maxn], cop[maxn], ctn[maxn], six[maxn], dp[maxn*10];
struct Product{
	int c;
	int k;
	int p;
} p[maxn];
struct Com{
	int c;
	int k;
} co[maxn][maxn];
int calc(int x, int pos){
	for(int i = b; i >= pos+1; i--)
		if(x > six[i])	x %= six[i];
	return x / six[pos];
}
int dfs(int sta){
	if(dp[sta] < 1e9)
		return dp[sta];
	int maxx = (1<<30);
	for(int i = 1; i <= s; i++)
	{
		int flag = 0;
		for(int j = 1; j <= con[i]; j++)
		{
			if(p[ctn[co[i][j].c]].k - calc(sta, ctn[co[i][j].c]) < co[i][j].k)
			{
				flag = 1;
				break;
			}
		}
		if(flag)	continue;
		int plus = 0;
		for(int j = 1; j <= con[i]; j++)
			plus += co[i][j].k * six[ctn[co[i][j].c]];
		maxx = min(maxx, dfs(sta + plus) + cop[i]);
	}
	for(int i = 1; i <= b; i++)
		if(p[i].k - calc(sta, i) >= 1)
			maxx = min(maxx, dfs(sta + six[i]) + p[i].p);
	return dp[sta] = maxx;
}
int main(void)
{
	memset(dp, 0x3f, sizeof(dp));
    scanf("%d", &b);
    int bas = 1, tp = 0;
    for(int i = 1; i <= b; i++)
    {
    	six[i-1] = bas;
    	scanf("%d %d %d", &p[i].c, &p[i].k, &p[i].p);
    	ctn[p[i].c] = i;
    	bas *= 6;
    	tp += bas*p[i].k;
    }
    six[b] = bas;
    dp[tp] = 0;
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
****UPD20201013：MLE了，转换为6进制状态压缩
cao怎么WA了
*/
