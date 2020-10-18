#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int sum[maxn], dp[maxn][maxn];
char str1[maxn], str2[maxn];
int dfs(int lf, int rt){
    if(rt < lf)          return 0;
    if(dp[lf][rt] < 1e9)  return dp[lf][rt];
    if(lf == rt)
        return dp[lf][rt] = 1;
    
    int minn = (1 << 30);
    minn = min(minn, 1 + dfs(lf + 1, rt));
    for(int k = lf + 1; k <= rt; k++)    
        if(str2[lf] == str2[k])
            minn = min(minn, dfs(lf, k - 1) + dfs(k + 1, rt));
    return dp[lf][rt] = minn;
}
int main(void)
{
    while(~scanf("%s", str1+1))
    {
        memset(dp, 0x3f, sizeof(dp));
        scanf("%s", str2+1);
        int len = strlen(str1+1);
        for(int i = 1; i <= len; i++)    dfs(1, i);
        sum[0] = 0;
        for(int i = 1; i <= len; i++)
        {
            sum[i] = dp[1][i];

            if(str1[i] == str2[i])    sum[i] = sum[i - 1];
            else
            {
                for(int j = 1; j <= i - 1; j++)
                    sum[i] = min(sum[i], sum[j] + dp[j + 1][i]);
            }
        }
        printf("%d\n", sum[len]);
    }
    system("pause");
    return 0;
}
