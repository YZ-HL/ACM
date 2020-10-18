#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn (1<<10)
#define int long long
using namespace std;
int t, l, r, k, c;
int dp[25][maxn][25], cnt[maxn], dis[maxn], nxc[maxn][maxn];
int calc(int x, int y){
	for(int i = y; i <= 9; i++)
		if(x & (1 << i))
			return (x ^ (1 << i)) | (1 << y);
	return x | (1 << y);
}
void inits(){
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < (1 << 10); i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			if(i & (1 << j))	cnt[i]++;
			nxc[i][j] = calc(i, j);
		}
	}
}
int dfs(int len, int sta, int lim, int zero){
	if(len <= 0)	return cnt[sta] == k;
	if(!lim && dp[len][sta][k] >= 0)
		return dp[len][sta][k];
	int res = 0;
	int limm = lim ? dis[len] : 9;
	for(int i = 0; i <= limm; i++)
		res += dfs(len-1, (i == 0 && zero) ? sta : nxc[sta][i], lim && i == limm, zero && i == 0);
	return lim ? res : dp[len][sta][k] = res;
}
int solve(int x, int k){
	int len = 0;
	while(x)
	{
		dis[++len] = x % 10;
		x /= 10;
	}
	return dfs(len, 0, 1, 1);
}
signed main(void)
{
	inits();
    scanf("%lld", &t);
    while(t--)
    {
    	scanf("%lld %lld %lld", &l, &r, &k);
    	printf("Case #%lld: %lld\n", ++c, solve(r, k) - solve(l - 1, k));
    }
    return 0;
}
/*
[X 该方案已废弃]
考虑设计状态dp[i位数字][序列长度为j][最长严格上升序列结尾的数为k]=数量
从小情况：
dp[0][0][0] = 0(边界 ?)
dp[1][1][0] = 1;
dp[1][1][1] = 1;
dp[1][1][2] = 1;
...
较大情况：
dp[2][2][0] = 0
dp[2][2][1] = 1
dp[2][2][2] = 2
dp[3][2][2] = 
...
推广到一般情况：
dp[i][j][k] = dp[i-1][j-1][j-1...k-1]+
			  dp[i-2][j-1][j-1...k-1]+
			  ...			
			  dp[j-1][j-1][j-1...k-1].
验证：
dp[2][2][2] = dp[1][1][1] = 1;
dp[3][2][3] = dp[2][1][1] + dp[2][1][2] +
			  dp[1][1][1] + dp[1][1][2] + 

【百度得】
dp[i][j][k]
i:位数
j:使用情况
k:LIS长度
dp[1][000...00][0] = 0
dp[1][000...00][1] = 0
dp[1][100...00][1] = 1
dp[1][010...00][1] = 1
dp[1][001...00][1] = 1
*/