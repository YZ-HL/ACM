#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int n, m, dp[maxn][maxn], vis[maxn][maxn];
char str1[maxn], str2[maxn];
int maps[maxn], score[maxn][maxn] = 
{{5, -1, -2, -1, -3},
 {-1, 5, -3, -2, -4},
 {-2, -3, 5, -2, -2},
 {-1, -2, -2, 5, -1},
 {-3, -4, -2, -1, -999}};
 void init(){
     maps['A'] = 0;
     maps['C'] = 1;
     maps['G'] = 2;
     maps['T'] = 3;
     maps['-'] = 4;
}
int dfs(int n1, int n2){
    if(!n1 && !n2)
        return dp[n1][n2] = 0;
    if(!n1 || !n2)
        return dp[n1][n2] = (n1 ? dfs(n1 - 1, n2) + score[maps[str1[n1]]][maps['-']] : dfs(n1, n2 - 1) + score[maps[str2[n2]]][maps['-']]);
    if(dp[n1][n2] < -1e8)
    {
        dp[n1][n2] = max(dp[n1][n2], dfs(n1 - 1, n2 - 1) + score[maps[str1[n1]]][maps[str2[n2]]]);
        dp[n1][n2] = max(dp[n1][n2], dfs(n1, n2 - 1) + score[maps[str2[n2]]][maps['-']]);
        dp[n1][n2] = max(dp[n1][n2], dfs(n1 - 1, n2) + score[maps['-']][maps[str1[n1]]]);
    }
    return dp[n1][n2];
}
int main(void)
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(dp, 0xce, sizeof(dp));
        scanf("%d %s", &n, str1+1);
        scanf("%d %s", &m, str2+1);
        printf("%d\n", dfs(n, m));
    }
    system("pause");
    return 0;
}
