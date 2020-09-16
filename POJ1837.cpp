#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 200005
#define INF 7500
#define move 10000
using namespace std;
int C, G, ans;
int CC[maxn];
int GG[maxn];
int dp[25][maxn];
int main(void)
{
    scanf("%d %d", &C, &G);
    for(int i = 1; i <= C; i++)
        scanf("%d", &CC[i]);
    for(int i = 1; i <= G; i++)
        scanf("%d", &GG[i]);
    dp[0][move] = 1; 
    for(int i = 1; i <= G; i++)
        for(int j = -INF; j <= INF; j++)
            for(int k = 1; k <= C; k++)
            {
                dp[i][j+move] += dp[i-1][j-GG[i]*CC[k]+move];
            }
    printf("%d\n", dp[G][move]);
    system("pause");
    return 0;
}
