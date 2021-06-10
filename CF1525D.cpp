/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 5005
using namespace std;
int n, a[maxn], dp[maxn][maxn];
int b1, b[maxn], c1, c[maxn];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] == 0 ? c[++c1] = i : b[++b1] = i;
    }
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i <= c1; i++)    dp[0][i] = 0;
    for(int i = 1; i <= b1; i++)
    {
        for(int j = i; j <= c1; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(b[i] - c[j]));
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[b1][c1]);
    return 0;
}
