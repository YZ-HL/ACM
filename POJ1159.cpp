//长度减去正串与反串的最长公共子序列长度即为插入字母数量
//正反串回文序列位置相对不变，减去LCS长度，剩下的都是需要添加字母进行配对的
//或递归求解
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 5005
using namespace std;
//卡内存一法
short n, dp[maxn][maxn];
char str[maxn];
int dp_search(int lf, int rt){
    if(rt < lf)
        return 0;
    if(dp[lf][rt] >= 0)
        return dp[lf][rt];
    if(str[lf] == str[rt])
        dp[lf][rt] = dp_search(lf+1, rt-1);
    else
        dp[lf][rt] = min(dp_search(lf+1, rt), dp_search(lf, rt-1)) + 1;
    return dp[lf][rt];
}
int main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    scanf("%s", str+1);
    printf("%d\n", dp_search(1, n));
    system("pause");
    return 0;
}
