#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 1005
using namespace std;
string r;
int len, dp[maxn][maxn];
int main(void)
{
	//memset(dp, -1, sizeof(dp));
    getline(cin, r);
    len = r.length();
    for(int i = 0; i <= len - 1; i++) dp[i][i] = 1;
    for(int i = 2; i <= len; i++)
    	for(int j = 0; j + i <= len; j++)
    	{
    		if(i == 2 && r[j] == r[j + i - 1])
    		{
    			dp[j][j + i - 1] = 1;
    			continue;
    		}
    		dp[j][j + i - 1] = (r[j] == r[j + i - 1] ? 1 : 0) & dp[j + 1][j + i - 2];
    	}
	int ans = 0;
	for(int i = 0; i <= len - 1; i++)
		for(int j = i; j <= len - 1; j++)
			if(dp[i][j] == 1)	
			{
				//printf("%d %d\n", i, j);
				ans = max(ans, j - i + 1);	
			}
	printf("%d", ans);
    return 0;
}
