#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int n, s;
double dp[maxn][maxn];
int main(void)
{
    scanf("%d %d", &n, &s);
    dp[n][s] = 0;
    for(int i = n; i >= 0; i--)
        for(int j = s; j >= 0; j--)
        {
            if(i == n && j == s)    continue;
            dp[i][j] = ( n * s + 
                         (n - i) * j * dp[i + 1][j] +
                         i * (s - j) * dp[i][j + 1] + 
                         (n - i) * (s - j) * dp[i + 1][j + 1] ) 
                         / (1.0 * (n * s - i * j));
        }
    //POJ特性
    printf("%.4f\n", (double)dp[0][0]);
    system("pause");
    return 0;
}
