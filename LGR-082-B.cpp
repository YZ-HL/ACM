#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, dp[3][maxn], vis[3][maxn];
int num1[maxn], num2[maxn];
int read(){
    char ch = getchar();
    while(ch != '0' && ch != '1')   ch = getchar();
    return ch - '0';
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)    num1[i] = read();
        for(int i = 1; i <= n; i++)    num2[i] = read();
        
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));

        if(num1[1] == 1 && num2[1] == 0)    dp[1][1] = 1, dp[2][1] = -1;
        if(num1[1] == 0 && num2[1] == 1)    dp[1][1] = -1, dp[2][1] = 1;

        for(int i = 2; i <= n; i++)
        {
            if(num1[i] == 1 && num1[i - 1] == 0)
                dp[1][i]++, dp[1][i - 1]--;
            if(num1[i] == 0 && num1[i - 1] == 1)
                dp[1][i]--, dp[1][i - 1]++;

            if(num2[i] == 1 && num1[i] == 0)
                dp[2][i]++, dp[1][i]--;
            if(num2[i] == 1 && num2[i - 1] == 0)
                dp[2][i]++, dp[2][i - 1]--;
            
            if(num2[i] == 0 && num1[i] == 1)
                dp[2][i]--, dp[1][i]++;
            if(num2[i] == 0 && num2[i - 1] == 1)
                dp[2][i]--, dp[2][i - 1]++;
        }

        
        for(int i = 1; i <= 2; i++)
            for(int j = 1; j <= n; j++)
                printf(j == n ? "%d\n" : "%d\t", dp[i][j]);
        

        if(abs(dp[1][1]) < 2)    vis[1][1] = 1;
        if(abs(dp[2][1]) < 2)    vis[2][1] = 1;
        if(dp[1][1] * dp[2][1] == -4)   vis[1][1] = vis[2][1] = 1;

        for(int i = 2; i <= n; i++)
        {
            if(abs(dp[1][i]) < 2)    vis[1][i] = 1;
            if(abs(dp[2][i]) < 2)    vis[2][i] = 1;
            if(dp[1][i] * dp[2][i] == -4)
                vis[1][i] = vis[2][i] = 1;
            if(dp[1][i] * dp[1][i - 1] == -4 && !vis[1][i] && !vis[1][i - 1])
                vis[1][i] = vis[1][i - 1] = 1;
            if(dp[2][i] * dp[2][i - 1] == -4 && !vis[2][i] && !vis[2][i - 1])
                vis[2][i] = vis[2][i - 1] = 1;
        }

        int flag = 1;
        for(int i = 1; i <= 2; i++)
            for(int j = 1; j <= n; j++)
                flag &= vis[i][j];

        printf(flag ? "RP\n" : "++\n");
    }
    return 0;
}
